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

#include "../include/game.h"

void Board::print()
{
    for (int i = 0; i < mHeight; ++i)
    {
        for (int j = 0; j < mWidth; ++j)
        {
            std::cout << "- ";
        }
        std::cout << '\n';
    }
}