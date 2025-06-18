#ifndef AGENT_H
#define AGENT_H

#include <queue>
#include <random>
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
    int served_clients;  // количество обслуженных клиентов
    std::random_device rd;
    std::mt19937 gen;
    std::exponential_distribution<> exp_dist;

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

    std::random_device rd;
    std::mt19937 gen;
    std::exponential_distribution<> exp_dist;
public:
    explicit InputFlow(Bank* b);
    void process_event(Event* ev) override;
};

#endif // AGENT_H
