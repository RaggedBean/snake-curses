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
        initialize();
    }

    void initialize()
    {
        srand(time(NULL)); //time

        score = 0;
        fruit = new Fruit(win.getRandomY(), win.getRandomX());
        snake = new Snake();
        snake->addPart((win.getInnerMaxY() / 2 + 1), (win.getInnerMaxX() / 2 + 1));
        snake->setDirection(DOWN);
    }


    void handleInput()
    {
        keypad(win.get(), TRUE);
        nodelay(win.get(), TRUE);
    
        int c = wgetch(win.get());
        switch(c)
        {
            case KEY_UP:
            case 'w':
                // Si dans la fenetre de jeu et si ne fait pas demi-tour
                if (snake->getHead().getY() - 1 >= win.getInnerMinY() && snake->getDirection() != DOWN) {
                    snake->setDirection(UP);
                }
                break;

            case KEY_DOWN:
            case 's':
                if (snake->getHead().getY() + 1 <= win.getInnerMaxY() && snake->getDirection() != UP) {
                    snake->setDirection(DOWN);
                }
                
                break;

            case KEY_LEFT:
            case 'a':
                if (snake->getHead().getX() - 1 >= win.getInnerMinX() && snake->getDirection() != RIGHT) {
                    snake->setDirection(LEFT);
                }
                break;

            case KEY_RIGHT:
            case 'd':
                if (snake->getHead().getX() + 1 <= win.getInnerMaxX() && snake->getDirection() != LEFT) {
                    snake->setDirection(RIGHT);
                }
                break;
        }
    }

    void update()
    {
        // SNAKE
        // position
        int oldTailPosY = snake->getTail().getY();
        int oldTailPosX = snake->getTail().getX();

        // move
        snake->move();
        win.remove(oldTailPosY, oldTailPosX); // Erase last part

        // display
        init_pair(SNAKE, snake->FG, snake->BG);
        wattron(win.get(), COLOR_PAIR(SNAKE));
        
        for (SnakePart& part : snake->getBody()) {
            win.add(part);
        }

        wattroff(win.get(), COLOR_PAIR(SNAKE));

        // FRUIT

        if (snake->getHead().getX() == fruit->getX() && snake->getHead().getY() == fruit->getY()) {
            snake->addPart(snake->getTail().getY(), snake->getTail().getX());
            score += 1;
            fruit->setY(win.getRandomY());
            fruit->setX(win.getRandomX());
        } 

        // display
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
    int score;
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