#pragma once

enum Type {
    RIGHT,
    CENTER,
    SCREENCENTER
};

enum TailDirection {
    left,
    right
};

class DialogBox {
    bool visible;
    int fontSize;

public:
    DialogBox ();
    ~DialogBox ();
};