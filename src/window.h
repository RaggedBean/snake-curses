#pragma once
#include <curses.h>

class Window {
public:
    Window(int height, int width)
    {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        win = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
        wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
        Refresh();  
    }

    void Refresh()
    {
        wrefresh(win); 
    }

private:
    WINDOW* win;
};
