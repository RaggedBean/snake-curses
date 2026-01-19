#pragma once
#include <ncurses.h>
#include "window.h"

class Game
{
public:
    Game(int h, int w) : win(h, w), game_over(false)
    {
        
    }


    void handleInput()
    {
        
    }

    void update()
    {
        //win.add(Drawable(3, 3, '@'));
    }

    void draw()
    {

    }

    bool isOver()
    {
        return game_over;
    }

private:
    bool game_over;
    Window win;
};