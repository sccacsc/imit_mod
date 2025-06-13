#ifndef MODEL_H
#define MODEL_H

#include <queue>

#include "event.h"

class Model{
private:
    std::priority_queue<Event, std::vector<Event>, std::greater<>> event_queue;
public:
    void add_event(Event e);
    void run();
};

#endif // MODEL_H
