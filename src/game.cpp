
#include <SFML/Graphics.hpp>

#include "cell.h"
#include "board.h"
#include "game.h"

Game::Game(int width, int height, int cellSize) : mWindow(sf::VideoMode(width * cellSize, height * cellSize), "Minesweeper"),
                                                  mBoard(width, height)
{
    mWindowHeight = height;
    mWindowWidth = width;
    mCellSize = cellSize;
}

// void Game::loadGamemWindow()
// {
//     // mWindow.create(sf::VideoMode(mWindowWidth, mWindowHeight), "Minesweeper");
// }

// void Game::setWidth(int width)
// {
//     mWindowWidth = width;
// }

// void Game::setHeight(int width)
// {
//     mWindowHeight = width;
// }

// bool Game::loadGamePieces()
// {
//     return (cell.loadFromFile("assets/Cell.png") 
//         && grayCell.loadFromFile("assets/GrayCell.png"));
// }

// void Game::setGamePieces()
// {
//     addCell.setTexture(cell);
//     addGrayCell.setTexture(grayCell);
// }


// void Game::setRectCoordinates(sf::IntRect &rect, int rectLeft, int rectTop, int rectWidth, int rectHeight)
// {
//     rect.left = rectLeft;
//     rect.top = rectTop;
//     rect.width = rectWidth;
//     rect.height = rectHeight; 
// }

// void Game::rectangleCoordinates()
// {
//     int squareNum = 0;
//     for (int i = 0; i < mWindowHeight/55; i++)
//     {
//         for (int j = 0; j < mWindowWidth/55; j++)
//         {
//             setRectCoordinates(square[squareNum], (i*55), (j*55), ((i*55) + 55), ((j*55) + 55));
//             ++squareNum;
//         } 
//     }
// }

// void Game::setPositionPieces(sf::Vector2i &pos, int left, int top)
// {
//     pos.x = left;
//     pos.y = top;
// }

// void Game::positionPiece()
// {
//     int pieceNum = 0;
//     for (int i = 0; i < mWindowHeight/55; i++)
//     {
//         for (int j = 0; j < mWindowWidth/55; j++)
//         {
//             setPositionPieces(position[pieceNum], (i*55), (j*55));
//             ++pieceNum;
//         } 
//     }
// }

// bool Game::isClickInBounds(int boardPos)
// {   
//     return event.mouseButton.x >= square[boardPos].left 
//         && event.mouseButton.x <= square[boardPos].width 
//         && event.mouseButton.y >= square[boardPos].top 
//         && event.mouseButton.y <= square[boardPos].height;
// }

// bool Game::takeTurn(int turn)
// {
    // for(int boardPos = 0; boardPos < 9; boardPos++)
    // {
    //     if(isClickInBounds(boardPos))
    //     {
    //         if(square[boardPos].left != -500)
    //         {
    //             // This goes in the recursion loop
    //             // piece[turn] = addGrayCell;
    //             // piece[turn].move((float)position[boardPos].x, (float)position[boardPos].y);
    //             square[boardPos].left = -500;
    //             return true;
    //         } 
    //         else 
    //         {
    //             return false;
    //         }
    //     }  
    // }
//     return false;
// }


void Game::run()
{
    // int cellSize = 25;
    // int width = 10;
    // int height = 10;
    // int boardSize = 390; // TODO
    // int turn = 0;

    // rectangleCoordinates();
    // positionPiece();
    // mWindow.setSize(sf::Vector2u(width * mCellSize, height * cellSize));
    sf::Event event;

    // mBoard.createBoard(mWindowWidth, mWindowHeight);
    while(mWindow.isOpen())
    {
        while(mWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                mWindow.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                int mouseX = sf::Mouse::getPosition(mWindow).x / mCellSize;
                int mouseY = sf::Mouse::getPosition(mWindow).y / mCellSize;
                // cout << "x: " << mouseX << " y: " << mouseY << '\n';
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mBoard.checkCell(mouseX, mouseY);
                }
            }
            

            // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            // {
                // takeTurn(turn);
                // turn++;
            // }
        }
        mWindow.clear();

        sf::Texture texture;
        // texture.setSmooth(true);
        // sf::Sprite sprite;
        sf::RectangleShape sprite;
        sprite.setOutlineThickness(.1f);
        sprite.setOutlineColor(sf::Color::Black);
        sprite.setSize(sf::Vector2f(mCellSize, mCellSize));
        // sprite.setScale(sf::Vector2f(.4, .4));

        for (int y = 0; y < mWindowHeight; ++y)
        {
            for (int x = 0; x < mWindowWidth; ++x)
            {
                texture.loadFromFile(ASSET_DIR + mBoard.getCell(x, y).texturePath());
                sprite.setPosition(sf::Vector2f(x * mCellSize, y * mCellSize));
                sprite.setTexture(&texture);
                mWindow.draw(sprite);
            }
        }
        

        // for(int index = 0; index < boardSize; index++)
        // {
        //     piece[index] = addCell;
        //     mWindow.draw(piece[index]);
        // }
        
        mWindow.display();
    }
}
