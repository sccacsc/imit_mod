#include "event.h"
#include "agent.h"

arrival_event::arrival_event(float t, Agent* a) : Event(t, a) {}
void arrival_event::execute() {
    agent->process_event(this);
}

service_end_event::service_end_event(float t, Agent* a) : Event(t, a) {}
void service_end_event::execute() {
    agent->process_event(this);
}
