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
Cell::Cell(float s, bool m)
{
    mIsMine = m;
    mSideLength = s;
    mNumNeighborMines = 0;
    mTexturePath = TEXTURE_PATHS[UNCHECKED];
}

/**
 * @brief return x-coordinate
 * 
 * @return int x-coordinate
 */
// int Cell::getXcoord()
// {
//     return coordinates.x;
// }

/**
 * @brief return y-coordinate
 * 
 * @return int y-coordinate
 */
// int Cell::getYCoord()
// {
//     return coordinates.y;
// }

/**
 * @brief Returns if the cell is a mine
 * 
 * @return true if cell is a mine
 * @return false if cell is not a mine
 */
bool& Cell::isMine()
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
// void Cell::setSize(float size)
// {
//     mSideLength = size;
// }

/**
 * @brief Set which image to display at render time for each cell
 * 
 * @param path string containing the new path
 */
// void Cell::setTexturePath(string path)
// {
//     if (path == "")
//     {
//         throw std::__throw_invalid_argument;
//     }
    
//     mTexturePath = path;
// }

/**
 * @brief Return the current texture object to render for the cell
 * 
 * @return sf::Texture& current texture object
 */
string& Cell::texturePath()
{
    return mTexturePath;
}
