#ifndef AGENT_H
#define AGENT_H

#include <queue>

class Event;
class Client;

class Agent{
public:
    virtual void process_event(Event ev) = 0;
};

class Bank : public Agent{ //кол-во эвентов = кол-ву кассиров
private:
    std::queue<Client> client_queue;
public:
    void new_client();
};

class Input_flow : public Agent{
private:
    Bank* bank;
public:
    Input_flow(Bank* b);
};


#endif // AGENT_H
