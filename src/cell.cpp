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

/**
 * @brief Construct a new Cell:: Cell object
 * 
 * @param s float length of side in pixels
 * @param m bool true if cell has mine, false otherwise
 * @param x int x-coordinate of upper left corner of cell
 * @param y int y-coordinate of upper left corner of cell
 */
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

/**
 * @brief Returns the RectangleShape object of a cell
 * 
 * @return sf::RectangleShape& the shape of the cell
 */
sf::RectangleShape& Cell::getShape()
{
    return rectShape;
}

int Cell::getSideLength()
{
    return mSideLength;
}

/**
 * @brief return x-coordinate
 * 
 * @return int x-coordinate
 */
int Cell::getXcoord()
{
    return coordinates.x;
}

/**
 * @brief return y-coordinate
 * 
 * @return int y-coordinate
 */
int Cell::getYcoord()
{
    return coordinates.y;
}

/**
 * @brief Returns if the cell is a mine
 * 
 * @return true if cell is a mine
 * @return false if cell is not a mine
 */
bool Cell::isMine()
{
    return mIsMine;
}

/**
 * @brief returns number of mines that the cell borders
 * 
 * @return int total number of surrounding mines
 */
int Cell::getNumMines()
{
    return mNumNeighborMines;
}

/**
 * @brief Set the side length of the cell, default is 55 px
 * 
 * @param size float size in pixels to set the side length to
 */
void Cell::setSize(float size=55)
{
    mSideLength = size;
}

/**
 * @brief Set which image to display at render time for each cell
 * 
 * @param path string containing the new path
 */
void Cell::setTexture(string path)
{
    texture.loadFromFile(path);
}

/**
 * @brief Return the current texture object to render for the cell
 * 
 * @return sf::Texture& current texture object
 */
sf::Texture& Cell::getTexture()
{
    return texture;
}
