/**
 * @file main.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief Spring 2021 CS151 final project - Minesweeper
 *         cpp function file
 * @date 2021-04-14
 *
 * @copyright Copyright (c) 2021
 *
 */
// #include "game.h"
#include "board.h"

/**
 * @brief Initialize the board vector and initialize each cell.
 * 
 * @param width 
 * @param height 
 */
void Board::createBoard(int width, int height)
{
    for (int y = 0; y < height; ++y)
    {
        vector<Cell> row;
        for (int x = 0; x < width; ++x)
        {
            Cell temp;
            temp.setTexturePath(ASSET_DIR + TEXTURE_PATHS[UNCHECKED]);
            row.push_back(temp);
        }
        mBoard.push_back(row);
    }
}

// void Board::print()
// {
//     for (long unsigned int i = 0; i < matrix.size(); ++i)
//     {
//         for (long unsigned int j = 0; j < matrix[i].size(); ++j)
//         {
//             std::cout << matrix[i][j];
//         }
//         std::cout << '\n';
//     }
// }

void Board::layMines()
{
    srand(time(NULL));
    int x, y, num;
    num = mMines;
    while (num > 0)
    {
        x = rand() % mWidth;
        y = rand() % mHeight;
        if (!mBoard[x][y].isMine())
        {
            mBoard[y][x].isMine() = true;
            num--;
        }
    }
}

Cell Board::getCell(int x, int y)
{
    return mBoard[y][x];
}

void Board::checkCell(int x, int y)
{
    bool isClicked = true;
    checkCell(x, y, isClicked);
}

/**
 * @brief Check cell and if mine, end game. Else, check surrounding cells recursively
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
void Board::checkCell(int x, int y, bool isClicked)
{
    // base case 1: out of bounds
    if (isClicked)
    {
        // alter clicked cell and check for bomb
    }
    
    if ((x < 0 || y < 0) || (x > mWidth || y > mHeight))
    {
        return;
    }
    // base case 2: current cell is bomb
    if (mBoard[y][x].isMine()) // is mine, game over
    {
        // if not clicked cell, return
        // else
            // set current cell mine to red?
            // expose board
            // end game
    }
    // recursive case
    else if ((x >=0 && y >= 0) && (x <= mWidth && y >= mHeight))
    {
        mBoard[y][x] = '_';         // reveal cell
        checkCell(x - 1, y);        // check left cell
        checkCell(x, y - 1);        // check top cell
        checkCell(x + 1, y);        // check right cell
        checkCell(x, y + 1);        // check bottom
        checkCell(x - 1, y - 1);    // check upper left
        checkCell(x + 1, y - 1);    // check upper right
        checkCell(x + 1, y + 1);    // check lower right
        checkCell(x - 1, y + 1);    // check lower left
    }
}