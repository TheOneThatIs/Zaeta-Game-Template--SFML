#pragma once

namespace zg {
    class Event;
};

class zg::Event {
public:
    Event ();
    ~Event ();

    virtual void startEvent ();
    virtual void endEvent ();

    virtual bool isEventComplete ();
    virtual bool isEventActivated ();
};