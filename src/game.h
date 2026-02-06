#pragma once
#include <ncurses.h>
#include "window.h"
#include "fruit.h"
#include "snake.h"

#include <iostream>

class Game
{
public:
    Game(int h, int w) : win(h, w), is_running(true)
    {
        initialize();
    }

    void initialize()
    {
        srand(time(NULL)); //time

        keypad(win.get(), TRUE);
        nodelay(win.get(), TRUE);

        score = 0;
        game_over = false;

        fruit = new Fruit(win.getRandomY(), win.getRandomX());
        snake = new Snake();
        snake->setDirection(DOWN);
        snake->setSize(3);
        for (int i = 0; i < snake->getSize(); i++) {
            snake->addPart((win.getInnerMaxY() / 2 + 1 - i), (win.getInnerMaxX() / 2 + 1));
        }
    }


    void handleInput()
    {  
        chtype ch = ERR;
        chtype tmp;

        while ((tmp = wgetch(win.get())) != ERR) {
            ch = tmp;
        }

        if (ch == ERR) return;

        switch(ch)
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
        init_pair(SNAKE, COLOR_YELLOW, COLOR_GREEN);
        wattron(win.get(), COLOR_PAIR(SNAKE));
        
        for (SnakePart& part : snake->getBody()) {
            win.add(part);
        }

        wattroff(win.get(), COLOR_PAIR(SNAKE));

        // FRUIT

        if (snake->getHead().getX() == fruit->getX() && snake->getHead().getY() == fruit->getY()) {
            // add segment
            snake->addPart(snake->getTail().getY(), snake->getTail().getX());
            score += 1;

            // spawn new fruit
            int fy, fx;
            bool isFree;

            // generate new fruit pos while pos is on snake body
            do { 
                fy = win.getRandomY();
                fx = win.getRandomX();
                isFree = true;

                for (SnakePart& part : snake->getBody()) {
                    if (part.getY() == fy && part.getX() == fx) {
                        isFree = false;
                        break;
                    }
                }
            } while (!isFree);

            fruit->setY(fy);
            fruit->setX(fx);
        }

        // check defeat conditions
        int head_y = snake->getHead().getY();
        int head_x = snake->getHead().getX();
        // border
        if (head_y == win.getInnerMinY() - 1
            || head_y == win.getInnerMaxY() + 1
            || head_x == win.getInnerMinX() - 1
            || head_x == win.getInnerMaxX() + 1) 
            {
                game_over = true;
            }
        // body
        for (SnakePart& part : snake->getBody()) {
            if (part.getY() == head_y && part.getX() == head_x && &part != &snake->getHead()) {
                game_over = true;
            }
        }

        
        // display
        init_pair(FRUIT, fruit->FG, fruit->BG);
        wattron(win.get(), COLOR_PAIR(FRUIT));
        win.add(*fruit);
        wattroff(win.get(), COLOR_PAIR(FRUIT));


        // GAME OVER
        if (game_over) {
            init_pair(SNAKE_OVER, COLOR_BLUE, COLOR_RED);
            wattron(win.get(), COLOR_PAIR(SNAKE_OVER));
            
            for (SnakePart& part : snake->getBody()) {
                win.addAt(part.getY(), part.getX(), part.getIcon());
                win.refresh();
                napms(150);
            }

            wattroff(win.get(), COLOR_PAIR(SNAKE_OVER));

            is_running = false;
        }        
    }

    void redraw()
    {
        win.refresh();

    }

    bool isRunning()
    {
        return is_running;
    }

    int getScore() { return score; }

private:
    bool is_running;

    int score;
    bool game_over;

    Window win;
    Fruit* fruit;
    Snake* snake;

    enum ColorsPairs : short {
        EMPTY = 0,
        SNAKE = 1,
        FRUIT = 2,
        SNAKE_OVER = 3,
    };

};