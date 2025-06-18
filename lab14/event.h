#ifndef EVENT_H
#define EVENT_H

class Agent;

class Event {
protected:
    float time;
    Agent* agent;
public:
    Event(float t, Agent* a) : time(t), agent(a) {}
    virtual ~Event() = default;
    virtual void execute() = 0;
    float get_time() const { return time; }
    bool operator>(const Event& other) const { return time > other.time; }
};

class arrival_event : public Event {
public:
    arrival_event(float t, Agent* a);
    void execute() override;
};

class service_end_event : public Event {
public:
    service_end_event(float t, Agent* a);
    void execute() override;
};

#endif // EVENT_H
