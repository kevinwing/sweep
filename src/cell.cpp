/**
 * @file cell.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "cell.h"

Cell::Cell(float s, bool m, int x, int y)
{
    mIsMine = m;
    mSideLength = s;
    mNumNeighborMines = 0;
    coordinates.x = x;
    coordinates.y = y;
    rectShape.setSize(sf::Vector2f(mSideLength, mSideLength));
    rectShape.setPosition(coordinates.x, coordinates.y);
    // texture.loadFromFile("../assets/unclickedCell.png");
}

void Cell::setMine(bool mine)
{
    mIsMine = mine;
}

void Cell::setX(int x)
{
    coordinates.x = x;
}

void Cell::setY(int y)
{
    coordinates.y = y;
}

bool Cell::isMine()
{
    return mIsMine;
}

sf::RectangleShape& Cell::getShape()
{
    return rectShape;
}

int Cell::getXcoord()
{
    return coordinates.x;
}

int Cell::getYcoord()
{
    return coordinates.y;
}

float Cell::getSideLength()
{
    return mSideLength;
}
// int getNumMines();
// void setSize(int size=55);
// void setTexture(string str);
// sf::Texture& getTexture();
// sf::RectangleShape& getShape();