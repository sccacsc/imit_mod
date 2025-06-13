#ifndef EVENT_H
#define EVENT_H

class Agent;

class Event{
private:
    float time;
    Agent* agent;
public:
    bool operator>(const Event& other) const {
        return time > other.time;
    }
};


class arrival_event : public Event{
public:
    arrival_event(Agent *a);
    ~arrival_event();
};

class service_end_event : public Event{
public:
    service_end_event(Agent *a);
    ~service_end_event();
};

#endif // EVENT_H
