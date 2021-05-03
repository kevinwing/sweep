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
    setNumMines();
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

void Board::setMines(int mines)
{
    mMines = mines;
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
        if (!mBoard[y][x].isMine())
        {
            // mBoard[y][x].texturePath() = TEXTURE_PATHS[MINE];
            mBoard[y][x].isMine() = true;
            num--;
        }
    }
}

bool Board::checkForMine(int x, int y)
{
    if (x < 0 || x >= mWidth || y < 0 || y >= mHeight)
    {
        return false;
    }
    return getCell(x, y).isMine();
}

void Board::setNumMines()
{
    for (int y = 0; y < mHeight; ++y)
    {
        for (int x = 0; x < mWidth; ++x)
        {
            if (getCell(x, y).isMine())
            {
                continue;
            }

            int count = 0;
            
            // upper
            if (checkForMine(x, y - 1))
            {
                ++count;
            }
            // upper right
            if (checkForMine(x + 1, y - 1))
            {
                ++count;
            }
            // right
            if (checkForMine(x + 1, y))
            {
                ++count;
            }
            // lower right
            if (checkForMine(x + 1, y + 1))
            {
                ++count;
            }
            // bottom
            if (checkForMine(x, y + 1))
            {
                ++count;
            }
            // lower left
            if (checkForMine(x - 1, y + 1))
            {
                ++count;
            }
            // left
            if (checkForMine(x - 1, y))
            {
                ++count;
            }
            // upper left
            if (checkForMine(x - 1, y - 1))
            {
                ++count;
            }
            getCell(x, y).numMines() = count;
            cout << count << ", " << getCell(x, y).numMines() << '\n';
        }
    }
}

Cell& Board::getCell(int x, int y)
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
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight)
    {
        return;
    }

    if (getCell(x, y).texturePath() == TEXTURE_PATHS[FLAG])
    {
        return;
    }

    // base case 2: current cell is bomb    
    if (getCell(x, y).isMine())
    {
        if (isClicked) // is mine, game over
        {
            showMines();
            // set current cell mine to red?
            // expose board
            
            // end game
            return;
        }
        return;
        // getCell(x, y).texturePath() = TEXTURE_PATHS[MINE];
        // count how many neighbor mines there are or get number of mines
    }
    // base case 3: current cell is empty
    else
    {

        if (getCell(x, y).numMines() > 0)
        {
            getCell(x, y).texturePath() = TEXTURE_PATHS[getCell(x, y).numMines()];
            return;
        }

        getCell(x, y).texturePath() = TEXTURE_PATHS[EMPTY];
        
        
        if (isClicked)
        {
            isClicked = false;
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

    // recursive case
}

void Board::showMines()
{
    for(int y = 0; y < mHeight; y++)
    {
        for (int x = 0; x < mWidth; x++)
        {
            if(getCell(x, y).texturePath() == TEXTURE_PATHS[FLAG])
            {
                if(!getCell(x, y).isMine())
                {
                    getCell(x, y).texturePath() = TEXTURE_PATHS[NOTMINE];
                }
                break;
            }
            else if(getCell(x, y).isMine())
            {
               getCell(x, y).texturePath() = TEXTURE_PATHS[EXPLODED];
            }
        }
    }
}