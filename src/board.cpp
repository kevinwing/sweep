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

Board::Board(int width, int height)
{
    mWidth = width;
    mHeight = height;
    mMines = 10;
    createBoard();
}

void Board::setSize(int width, int height)
{
    mWidth = width;
    mHeight = height;
    mBoard.clear();
    createBoard();
}

/**
 * @brief Initialize the board vector and initialize each cell.
 * 
 * @param width 
 * @param height 
 */
void Board::createBoard()
{
    for (int y = 0; y < mHeight; ++y)
    {
        vector<Cell> row;
        for (int x = 0; x < mWidth; ++x)
        {
            Cell temp;
            temp.texturePath() = TEXTURE_PATHS[UNCHECKED];
            row.push_back(temp);
        }
        mBoard.push_back(row);
    }
    layMines();
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
        if (!mBoard[y][x].isMine())
        {
            // mBoard[y][x].texturePath() = TEXTURE_PATHS[MINE];
            mBoard[y][x].isMine() = true;
            num--;
        }
    }
}

Cell& Board::getCell(int x, int y)
{
    // cout << "Y size: " << mBoard.size() << '\n';
    // cout << "X size: " << mBoard[y].size() << '\n';

    // if (x < 0 || x >= mWidth)
    // {
    //     cout << "x: " << x << '\n';
    // }

    // if (y < 0 || y >= mHeight)
    // {
    //     cout << "y: " << y << '\n';
    // }

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
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight)
    {
        return;
    }

    // base case 2: current cell is bomb    
    if (getCell(x, y).isMine())
    {
        if (isClicked) // is mine, game over
        {
            getCell(x, y).texturePath() = TEXTURE_PATHS[EXPLODED];
            // set current cell mine to red?
            // expose board
            // end game
            return;
        }
        // getCell(x, y).texturePath() = TEXTURE_PATHS[MINE];
        // count how many neighbor mines there are or get number of mines
    }
    // base case 3: current cell is empty
    else
    {
        if (getCell(x, y).getNumMines() > 0)
        {
            // display numbered empty square
            return;
        }
        else
        {
            // set texture to empty
            getCell(x, y).texturePath() = TEXTURE_PATHS[EMPTY];
        }
        
        
        // implement memoization for is the cell already visited

        if ((x - 1) >= 0 && getCell(x - 1, y).texturePath() == TEXTURE_PATHS[UNCHECKED])
        {
            checkCell(x - 1, y, isClicked);        // check left cell
        }
    
        if ((y - 1) >= 0 && getCell(x, y - 1).texturePath() == TEXTURE_PATHS[UNCHECKED])
        {
            checkCell(x, y - 1, isClicked);        // check top cell
        }

        if ((x + 1) < mWidth && getCell(x + 1, y).texturePath() == TEXTURE_PATHS[UNCHECKED])
        {
            checkCell(x + 1, y, isClicked);        // check right cell
        }

        if ((y + 1) < mHeight && getCell(x, y + 1).texturePath() == TEXTURE_PATHS[UNCHECKED])
        {
            checkCell(x, y + 1, isClicked);        // check bottom
        }

        // checkCell(x - 1, y - 1, isClicked);    // check upper left
        // checkCell(x + 1, y - 1, isClicked);    // check upper right
        // checkCell(x + 1, y + 1, isClicked);    // check lower right
        // checkCell(x - 1, y + 1, isClicked);    // check lower left
    }
    

    if (isClicked)
    {
        isClicked = false;
    }
    
    // recursive case
}