#pragma once

#include <ncurses.h>
#include <random>

#include "drawable.h"


class Snake : public Drawable
{
private:
    int y, x;
    char icon;
public:
    Snake(int y, int x) : Drawable(x, y, '@') {
        
    }

    ~Snake() {

    }
    
    enum Colors {
        FG = COLOR_YELLOW,
        BG = COLOR_GREEN
    };
};

