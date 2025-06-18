#include "event.h"
#include "agent.h"

ArrivalEvent::ArrivalEvent(float t, Agent* a) : Event(t, a) {}
void ArrivalEvent::execute() {
    agent->process_event(this);
}

ServiceEndEvent::ServiceEndEvent(float t, Agent* a) : Event(t, a) {}
void ServiceEndEvent::execute() {
    agent->process_event(this);
}
