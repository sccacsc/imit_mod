#include <random>
#include <QDebug>
#include "agent.h"
#include "event.h"
#include "model.h"

extern Model* global_model;

InputFlow::InputFlow(Bank* b) : bank(b), gen(rd()), exp_dist(0.9) {}

void InputFlow::process_event(Event* ev) {
    qDebug() << "Клиент пришёл в" << ev->get_time();
    bank->new_client();

    float next_time = ev->get_time() + exp_dist(gen);
    global_model->add_event(new arrival_event(next_time, this));
}

Bank::Bank(int num_cashiers) : free_cashiers(num_cashiers), served_clients(0), gen(rd()), exp_dist(0.3) {
}

void Bank::new_client() {
    if (free_cashiers > 0) {
        free_cashiers--;
        qDebug() << "Обсуживание клиента началось, свободных окон -" << free_cashiers;
        global_model->add_event(new service_end_event(global_model->current_time() + exp_dist(gen), this));
    } else {
        client_queue.push(Client());
        qDebug() << "Клиент в очереди, длина очереди -" << client_queue.size();
    }
}



void Bank::process_event(Event* ev) {
    qDebug() << "Клиента обслужили в " << ev->get_time();
    served_clients++;  // увеличиваем счётчик
    free_cashiers++;

    if (!client_queue.empty()) {
        client_queue.pop();
        free_cashiers--;
        qDebug() << "Обсуживание клинета из очереди началось, длина очереди -" << client_queue.size() << "свободных окон -" << free_cashiers;
        global_model->add_event(new service_end_event(global_model->current_time() + exp_dist(gen), this));
    }
}


int Bank::queue_size() const {
    return client_queue.size();
}
