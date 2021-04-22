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

Cell::Cell(int s, bool m, int xC, int yC)
{
    mIsMine = m;
    mSideLength = s;
    mNumNeighborMines = 0;
    mCoordinateX = xC;
    mCoordinateY = yC;
    rectShape.setSize(sf::Vector2f(mSideLength, mSideLength));
    texture.loadFromFile("../assets/unclickedCell.png");
}