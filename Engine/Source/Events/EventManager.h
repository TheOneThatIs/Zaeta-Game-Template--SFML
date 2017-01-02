#pragma once
#include<vector>

#include "Event.h"

class EventManager {
public:
    std::vector<zg::Event*> v_events;
    EventManager ();
    ~EventManager ();

    void addEvent (zg::Event* event);
};