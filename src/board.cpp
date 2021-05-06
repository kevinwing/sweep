/**
 * @file main.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief board class function file
 * @date 2021-04-14
 *
 * @copyright Copyright (c) 2021
 *
 */
// #include "game.h"
#include "board.h"

/**
 * @brief Construct a new Board:: Board object
 * 
 * @param width width of the board
 * @param height height of the board
 */
Board::Board(int width, int height)
{
    mWidth = width;
    mHeight = height;
    mMines = 10;
    gameStatus = false;
    mIsWon = true;
    createBoard();
}

/**
 * @brief clears the old board's parameters and creates a new one with new parameters
 * 
 * @param width new width of the board
 * @param height new height of the board
 */
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
 * @param width width of the board
 * @param height height of the board
 */
void Board::createBoard()
{
    for (int y = 0; y < mHeight; ++y)
    {
        vector<Cell> row;
        for (int x = 0; x < mWidth; ++x)
        {
            Cell current;
            row.push_back(current); // set texture after push
        }
        mBoard.push_back(row); // pre-emptive push to preserve texture
    }
    // initTextures();
    layMines();
    countNeighborMines();
}

/**
 * @brief Sets the number of mines that will be placed on the board
 * 
 * @param mines number of mines
 */
void Board::setMines(int mines)
{
    mMines = mines;
}

// void Board::initTextures()
// {
//     for (size_t y = 0; y < mBoard.size(); ++y)
//     {
//         for (size_t x = 0; x < mBoard[y].size(); ++x)
//         {
//             mBoard[y][x].setRectTexture(ASSET_DIR + TEXTURE_PATHS[UNCHECKED]);
//             mBoard[y][x].getShape().setSize(sf::Vector2f(mWidth, mHeight));
//         }
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
            mBoard[y][x].isMine() = true;
            num--;
        }
    }
}

/**
 * @brief Recursively checks around a clicked cell to find out
 * how many mines are adjacent to it
 * 
 * @param x cell x-coordinate
 * @param y cell y-coordinate
 * @return true 
 * @return false 
 */
bool Board::checkForMine(int x, int y)
{
    if (x < 0 || x >= mWidth || y < 0 || y >= mHeight)
    {
        return false;
    }
    return getCell(x, y).isMine();
}

void Board::countNeighborMines()
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
        }
    }
}

/**
 * @brief Sets the number of available flags
 * 
 * @param flags 
 */
void Board::setNumFlags(int flags)
{
    mFlags = flags;
}

/**
 * @brief Adds to the total number of flags
 * 
 */
void Board::addFlag()
{
    ++mFlags;
}

/**
 * @brief Subtracts from the total number of flags
 * 
 */
void Board::subtractFlag()
{
    --mFlags;
}

/**
 * @brief Checks if the player has run out of flags
 * 
 * @return true 
 * @return false 
 */
bool Board::noFlags()
{
    if(mFlags == 0)
    {
        return true;
    }

    return false;
}

/**
 * @brief Returns the cell as a certain window coordinate
 * 
 * @param x window x-coordinate
 * @param y window y-coordinate
 * @return Cell& 
 */
Cell& Board::getCell(int x, int y)
{   
    return mBoard[y][x];
}

/**
 * @brief Checks if a cell has been clicked
 * 
 * @param x window x-coordinate
 * @param y window y-coordinate
 */
void Board::checkCell(int x, int y)
{
    bool isClicked = true;
    checkCell(x, y, isClicked);
}

/**
 * @brief Check cell and if mine, end game. Else, check surrounding cells recursively
 *
 * @param x window x-coordinate
 * @param y window y-coordinate
 * @return true
 * @return false
 */
void Board::checkCell(int x, int y, bool isClicked)
{
    // create a pointer to current cell
    Cell *cellPtr = &getCell(x, y);
    // base case 1: out of bounds
    if (x < 0 || y < 0 || x >= mWidth || y >= mHeight ||
        cellPtr->texturePath() == TEXTURE_PATHS[FLAG])
    {
        cellPtr = nullptr;
        return;
    }


    // if (cellPtr->texturePath() == TEXTURE_PATHS[FLAG])
    // {
    //     return;
    // }

    // base case 2: current cell is bomb    
    if (cellPtr->isMine())
    {
        if (isClicked) // is mine, game over
        {
            showMines();
            // expose board
            // end game
            cellPtr = nullptr;
            mIsWon = false;
            return;
        }
        return;
    }

    // base case 3: current cell is empty
    else
    {
        // cellPtr->texturePath() = TEXTURE_PATHS[getCell(x, y).numMines()];

        if (cellPtr->numMines() > 0)
        {
            cellPtr->texturePath() = TEXTURE_PATHS[getCell(x, y).numMines()];
            return;
        }

        // getCell(x, y).setRectTexture(TEXTURE_PATHS[EMPTY]);
        cellPtr->texturePath() = TEXTURE_PATHS[EMPTY];
        
        
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
    }
    cellPtr = nullptr;
}

/**
 * @brief Shows all currently concealed mines in the event of a loss
 * 
 */
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
            }
            else if(getCell(x, y).isMine())
            {
               getCell(x, y).texturePath() = TEXTURE_PATHS[EXPLODED];
            }
        }
    }

    gameStatus = true;
}

/**
 * @brief gets the game status attached to the board, either game over or not game over
 * 
 * @return true 
 * @return false 
 */
bool Board::getGameStatus()
{
    return gameStatus;
}

/**
 * @brief sets the game status to true or false
 * 
 * @param game game over/not game over variable
 */
void Board::setGameStatus(bool game)
{
    gameStatus = game;
}

bool& Board::isWon()
{
    return mIsWon;
}

// bool Board::checkConditions()
// {
//     int numCells = (mWidth * mHeight) - mMines;
//     for (int y = 0; y < mHeight; ++y)
//     {
//         for (int x = 0; x < mWidth; ++x)
//         {
//             if (mBoard[y][x].texturePath() != TEXTURE_PATHS[UNCHECKED])
//             {
//                 --numCells; // decrement, if reaches 0 without clicking mine, game is won
//             }
//         }
//     }
    
//     if (numCells == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }