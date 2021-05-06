/**
 * @file cell.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief 
 * @date 2021-04-22
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
Cell::Cell(int s, bool m, string path)
{
    mIsMine = m;
    mRectWidth = s;
    mRectHeight = s;
    mNumNeighborMines = 0;
    mTexturePath = path;

    mTexture.loadFromFile(ASSET_DIR + TEXTURE_PATHS[UNCHECKED]);
    mRect.setSize(sf::Vector2f(mRectWidth, mRectHeight));
    mRect.setTexture(&mTexture);
}

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
int& Cell::numMines()
{
    return mNumNeighborMines;
}
