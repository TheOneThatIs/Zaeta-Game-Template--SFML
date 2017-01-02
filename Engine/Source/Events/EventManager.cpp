#include "Events\EventManager.h"


EventManager::EventManager () {

}

EventManager::~EventManager () {}

void EventManager::addEvent (zg::Event* event) {
    v_events.push_back (event);
}