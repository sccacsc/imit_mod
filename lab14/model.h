#ifndef MODEL_H
#define MODEL_H

#include <queue>
#include <vector>
#include "event.h"

class Model {
private:
    std::priority_queue<Event*, std::vector<Event*>,
                        bool(*)(Event* a, Event* b)> event_queue;
    float current;
public:
    Model();
    void add_event(Event* e);
    void run_step();
    float current_time() const;
    bool has_events() const;
};

extern Model* global_model;

#endif // MODEL_H
