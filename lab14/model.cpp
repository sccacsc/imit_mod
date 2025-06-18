#include "model.h"

Model* global_model = nullptr;

bool event_compare(Event* a, Event* b) {
    return a->get_time() > b->get_time();
}

Model::Model() : event_queue(event_compare), current(0.0f) {}

void Model::add_event(Event* e) {
    event_queue.push(e);
}

void Model::run_step() {
    if (!event_queue.empty()) {
        Event* e = event_queue.top();
        current = e->get_time();
        event_queue.pop();
        e->execute();
        delete e;
    }
}

float Model::current_time() const {
    return current;
}

bool Model::has_events() const {
    return !event_queue.empty();
}
