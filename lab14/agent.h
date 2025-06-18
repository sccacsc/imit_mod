#ifndef AGENT_H
#define AGENT_H

#include <queue>
#include "client.h"

class Event;

class Agent {
public:
    virtual void process_event(Event* ev) = 0;
};

class Bank : public Agent {
private:
    std::queue<Client> client_queue;
    int free_cashiers;  // число свободных кассиров
    int served_clients = 0;  // количество обслуженных клиентов
public:
    Bank(int num_cashiers);
    void new_client();
    void process_event(Event* ev) override;
    int queue_size() const;
    int served() const { return served_clients; }
};


class InputFlow : public Agent {
private:
    Bank* bank;
public:
    explicit InputFlow(Bank* b);
    void process_event(Event* ev) override;
};

#endif // AGENT_H
