#pragma once

#include <ncurses.h>
#include <random>

#include "drawable.h"


class Fruit : public Drawable
{
private:
    int y, x;
    char icon;
public:
    Fruit(int y, int x) : Drawable(x, y, 'o') {

    }

    ~Fruit() {

    }

    void setColor(int fg, int bg) {

    }

    enum Colors {
        FG = COLOR_RED,
        BG = 0
    };
    
};

