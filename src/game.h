#pragma once
#include <ncurses.h>
#include "window.h"
#include "fruit.h"
#include "snake.h"

#include <iostream>

class Game
{
public:
    Game(int h, int w) : win(h, w), game_over(false)
    {
        fruit = new Fruit(win.getRandomY(), win.getRandomX());
        snake = new Snake( (win.getInnerMaxY() / 2 + 1), (win.getInnerMaxX() / 2 + 1) );
    }


    void handleInput()
    {
        
    }

    void update()
    {
        //win.add(Drawable(3, 3, '@'));
        
        // snake
        init_pair(SNAKE, snake->FG, snake->BG);
        wattron(win.get(), COLOR_PAIR(SNAKE));
        win.add(*snake);
        wattroff(win.get(), COLOR_PAIR(SNAKE));

        // fruit
        init_pair(FRUIT, fruit->FG, fruit->BG);
        wattron(win.get(), COLOR_PAIR(FRUIT));
        win.add(*fruit);
        wattroff(win.get(), COLOR_PAIR(FRUIT));
        
    }

    void redraw()
    {
        win.refresh();

    }

    bool isOver()
    {
        return game_over;
    }

private:
    bool game_over;
    Window win;
    Fruit* fruit;
    Snake* snake;

    enum ColorsPairs : short {
        EMPTY = 0,
        SNAKE = 1,
        FRUIT = 2,
    };
};