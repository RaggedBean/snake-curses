#pragma once
#include <ncurses.h>

class Drawable
{
public:
    Drawable() {
        y = x = 0;
        icon = ' ';
    }

    Drawable(int y, int x, char ch) {
        this->y = y;
        this->x = x;
        this->icon = ch;
    }

    void setX(int x) {this-> x = x; }
    void setY(int y) {this-> y = y; }

    int getX() { return x; }
    int getY() { return y; }
    char getIcon() { return icon; }

    void clear() {
        mvaddch(y, x, ' ');
    }

private:
    int y, x;
    char icon;
};