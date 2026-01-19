#include <ncurses.h>

#include <iostream>

#include "window.h"
#include "game.h"

const int BOARD_DIM = 25;
const int HEIGHT = BOARD_DIM ;
const int WIDTH = BOARD_DIM;

using namespace std;


int main(int argc, char **argv)
{
    initscr(); // Start ncurses
    cbreak();
    noecho();
    refresh();


    Game game = Game(HEIGHT, WIDTH);

    while (!game.isOver()) {
        // handle input
        game.handleInput();
        
        // update
        game.update();

        // display
        game.draw();
    }
    

    getch();

    endwin(); // End ncurses
    return 0;
}
