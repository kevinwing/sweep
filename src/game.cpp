
#include <SFML/Graphics.hpp>

#include "game.h"

void Game::loadGameWindow()
{
    setWidth();
    setHeight();
    window.create(sf::VideoMode(windowWidth, windowHeight), "Minesweeper");
}

void Game::setWidth()
{
    windowWidth = 1430;
}

void Game::setHeight()
{
    windowHeight = 825;
}

bool Game::loadGamePieces()
{
    return (cell.loadFromFile("assets/Cell.png") 
        && grayCell.loadFromFile("assets/GrayCell.png"));
}

void Game::setGamePieces()
{
    addCell.setTexture(cell);
    addGrayCell.setTexture(grayCell);
}


void Game::setRectCoordinates(sf::IntRect &rect, int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
    rect.left = rectLeft;
    rect.top = rectTop;
    rect.width = rectWidth;
    rect.height = rectHeight; 
}

void Game::rectangleCoordinates()
{
    int squareNum = 0;
    for (int i = 0; i < windowHeight/55; i++)
    {
        for (int j = 0; j < windowWidth/55; j++)
        {
            setRectCoordinates(square[squareNum], (i*55), (j*55), ((i*55) + 55), ((j*55) + 55));
            ++squareNum;
        } 
    }
}

void Game::setPositionPieces(sf::Vector2i &pos, int left, int top)
{
    pos.x = left;
    pos.y = top;
}

void Game::positionPiece()
{
    int pieceNum = 0;
    for (int i = 0; i < windowHeight/55; i++)
    {
        for (int j = 0; j < windowWidth/55; j++)
        {
            setPositionPieces(position[pieceNum], (i*55), (j*55));
            ++pieceNum;
        } 
    }
}

bool Game::isClickInBounds(int boardPos)
{   
    return event.mouseButton.x >= square[boardPos].left 
        && event.mouseButton.x <= square[boardPos].width 
        && event.mouseButton.y >= square[boardPos].top 
        && event.mouseButton.y <= square[boardPos].height;
}

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


void Game::gameLoop()
{
    int boardSize = 390; // TODO
    // int turn = 0;

    rectangleCoordinates();
    positionPiece();

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            // {
                // takeTurn(turn);
                // turn++;
            // }
        }
        window.clear(sf::Color(255, 255, 255));
        for(int index = 0; index < boardSize; index++)
        {
            piece[index] = addCell;
            window.draw(piece[index]);
        }
        window.display();
    }
}
