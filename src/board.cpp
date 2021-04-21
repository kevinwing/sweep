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
#include <cstdlib>
#include <ctime>

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