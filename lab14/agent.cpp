#include <random>
#include <QDebug>
#include "agent.h"
#include "event.h"
#include "model.h"

// Глобальная модель
extern Model* global_model;

// Создаем генератор и распределение один раз
static std::random_device rd;
static std::mt19937 gen(rd());
static std::exponential_distribution<> exp_dist_arv(0.9);  // λ = 0.5, среднее = 2.0
static std::exponential_distribution<> exp_dist_serv(0.5);

InputFlow::InputFlow(Bank* b) : bank(b) {}

void InputFlow::process_event(Event* ev) {
    qDebug() << "Клиент пришёл в" << ev->get_time();
    bank->new_client();

    float next_time = ev->get_time() + exp_dist_arv(gen);
    global_model->add_event(new ArrivalEvent(next_time, this));
}

// В конструкторе задаём количество кассиров
Bank::Bank(int num_cashiers) : free_cashiers(num_cashiers) {}

void Bank::new_client() {
    if (free_cashiers > 0) {
        free_cashiers--;
        qDebug() << "Обсуживание клиента началось, свободных окон -" << free_cashiers;
        global_model->add_event(new ServiceEndEvent(global_model->current_time() + exp_dist_serv(gen), this));
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
        global_model->add_event(new ServiceEndEvent(global_model->current_time() + 2.0f, this));
    }
}


int Bank::queue_size() const {
    return client_queue.size();
}
