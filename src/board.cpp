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

#include "game.h"

void Board::setUp()
{
    for (int i = 0; i < mHeight; ++i)
    {
        vector<char> temp;
        for (int j = 0; j < mWidth; ++j)
        {
            temp.push_back('-');
        }
        matrix.push_back(temp);
    }
}

void Board::print()
{
    for (long unsigned int i = 0; i < matrix.size(); ++i)
    {
        for (long unsigned int j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}

void Board::layMines()
{
    srand(time(NULL));
    int x, y, num;
    num = mMines;
    while (num > 0)
    {
        x = rand() % mWidth;
        y = rand() % mHeight;
        if (matrix[x][y] == '-')
        {
            matrix[x][y] = 'B';
            num--;
        }
    }
}

/**
 * @brief Check cell and if mine, end game. Else, check surrounding cells recursively
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
void Board::checkCell(int x, int y)
{
    // base case 1: out of bounds
    if ((x < 0 || y < 0) || (x > mWidth || y > mHeight))
    {
        return;
    }
    // base case 2: current cell is bomb
    if (matrix[x][y] == 'B') // is mine, game over
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
        matrix[x][y] = '_';         // reveal cell
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