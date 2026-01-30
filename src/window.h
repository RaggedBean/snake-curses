#pragma once
#include <ncurses.h>
#include <iostream>
#include <random>

#include "drawable.h"

class Window {
public:

    Window(int h, int w) : height(h), width(w)
    {
        initialize(h, w);
    }


    void initialize(int height, int width) {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        window = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
        wtimeout(window, 1000);

        clear();
        drawBorder();
        refresh();
    }

    void clear() {
        wclear(window);
    }

    void drawBorder() {
        wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
    }

    void refresh() {
        wrefresh(window);
    }

    void add(Drawable drawable) {
        addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
    }

    void addAt(int y, int x, char ch) {
        mvwaddch(window, y, x, ch);
    }

    void remove(int y, int x) {
        mvwaddch(window, y, x, ' ');
    }
    
    WINDOW* get() {  return window; }

    int getInnerMinY() const { return 1; }
    int getInnerMaxY() const { return height - 2; }
    int getInnerMinX() const { return 1; }
    int getInnerMaxX() const { return width - 2; }

    int getRandomY() { return randomNumber(getInnerMinY(), getInnerMaxY()); }
    int getRandomX() { return randomNumber(getInnerMinY(), getInnerMaxY()); }

    int randomNumber(int min, int max) {
        std::random_device rd; // seed
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);

        int i = dist(gen);
        return i;
    }

    

private:
    WINDOW *window;
    int height;
    int width;

};
