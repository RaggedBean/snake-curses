#pragma once
#include <ncurses.h>

#include "drawable.h"

class Window {
public:

    Window(int height, int width)
    {
        initialize(height, width);
    }


    void initialize(int height, int width) {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        window = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));

        wclear(window);
        wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
        refresh();  
    }

    void refresh() {
        wrefresh(window);
    }

    void add(Drawable drawable) {
        mvwaddch(window, drawable.getY(), drawable.getX(), drawable.getIcon());
        wrefresh(window);
    }

private:
    WINDOW *window;

};
