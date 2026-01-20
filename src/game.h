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
        
        win.add(*fruit);
        win.add(*snake);
    }

    void draw()
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
};