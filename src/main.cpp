#include <curses.h>

#include <iostream>

#include "window.h"

const int BOARD_DIM = 25;
const int WIDTH = BOARD_DIM;
const int HEIGHT = BOARD_DIM;

using namespace std;


int main(void)
{
    initscr(); // Start ncurses
    cbreak();
    noecho();
    refresh();

    Window win(WIDTH, HEIGHT);
    // win.Refresh();

    


    int c = getch();

    endwin(); // End ncurses
    return 0;
}
