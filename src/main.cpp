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
    curs_set(0);
    cbreak();
    noecho();

    if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
    start_color();

    refresh();


    Game game = Game(HEIGHT, WIDTH);

    while (game.isRunning()) {
        // handle input
        game.handleInput();
        
        // update
        game.update();

        // display
        game.redraw();

        napms(150);   // Game speed
    }
    

    getch();

    endwin(); // End ncurses

    std::cout << "game over" << std::endl;
    std::cout << "Your score: " << game.getScore() << std::endl;
    return 0;
}
