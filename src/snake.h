#pragma once

#include <ncurses.h>
#include <random>
#include <vector>

#include "drawable.h"

enum Direction : short {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};


class SnakePart : public Drawable
{
public:
    SnakePart(int y, int x) : Drawable(x, y, 'o') {
        
    }

    void move(short dir) {
        
        switch(dir)
        {
        case UP:
            setY(getY() - 1);
            break;
        case DOWN:
            setY(getY() + 1);
            break;
        case LEFT:
            setX(getX() - 1);
            break;
        case RIGHT:
            setX(getX() + 1);
            break;
        }
    };
};


class Snake
{
private:
    short currentDirection;
    int size = 3;
    std::vector<SnakePart> snakeParts;

public:
    Snake() {

    }

    ~Snake() {

    }
    
    void move()
    {
        int row = getHead().getY();
        int col = getHead().getX();

        for (int i = snakeParts.size() - 1; i > 0; --i) {
            snakeParts[i].setX(snakeParts[i - 1].getX());
            snakeParts[i].setY(snakeParts[i - 1].getY());
        }

        switch(currentDirection) 
        {
        case UP:
            row--;
            break;
        case DOWN:
            row++;
            break;
        case LEFT:
            col--;
            break;
        case RIGHT:
            col++;
            break;
        }

        getHead().setY(row);
        getHead().setX(col);
        
    }


    void addPart(int y, int x) {
        snakeParts.push_back(SnakePart(y, x));
    }

    SnakePart& getHead() {
        return snakeParts.front();
    };

    SnakePart& getTail() {
        return snakeParts.back();
    }

    std::vector<SnakePart>& getBody() { return snakeParts; }

    int getSize() { return size; }
    void setSize(int s) { size = s; }

    short getDirection() { return currentDirection; }
    void setDirection(short dir) { currentDirection = dir; }


};

