
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

void Game::menu()
{
    sf::RectangleShape shape1(sf::Vector2f(60.0f, 30.0f));
    shape1.setFillColor(sf::Color::Green);
    shape1.setPosition(125, 40);

    sf::RectangleShape shape2(sf::Vector2f(60.0f, 30.0f));
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition(125, 140);

    sf::RectangleShape shape3(sf::Vector2f(60.0f, 30.0f));
    shape3.setFillColor(sf::Color::Red);
    shape3.setPosition(125, 240);

    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                int mouseX = sf::Mouse::getPosition(mWindow).x;
                int mouseY = sf::Mouse::getPosition(mWindow).y;
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (shape1.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        std::cout << "Square 1 was pressed!\n";
                        run(8, 10);
                    }
                    if (shape2.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        std::cout << "Square 2 was pressed!\n";
                        run(14, 18);
                    }
                    if (shape3.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        std::cout << "Square 3 was pressed!\n";
                        run(20, 24);
                    }
                }
            }
        }
        mWindow.clear();
        mWindow.draw(shape1);
        mWindow.draw(shape2);
        mWindow.draw(shape3);
        mWindow.display();
    }
}

void Game::run(int width, int height)
{
    // int cellSize = 25;
    // int width = 10;
    // int height = 10;
    // int boardSize = 390; // TODO
    // int turn = 0;

    mWindowWidth = width;
    mWindowHeight = height;
    mBoard.setSize(width, height);
    sf::View view = mWindow.getView();
    sf::Vector2f size = static_cast<sf::Vector2f>(mWindow.getSize());
    size = (sf::Vector2f(mWindowWidth * mCellSize, mWindowHeight * mCellSize));
    view.setCenter(size/2.f);
    view.setSize(size);
    mWindow.setSize(static_cast<sf::Vector2<unsigned int> >(size));
    mWindow.setView(sf::View(sf::FloatRect(0.f, 0.f, size.x, size.y)));

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

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mBoard.checkCell(mouseX, mouseY);
                }

                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    Cell *temp = &mBoard.getCell(mouseX, mouseY);
                    if (temp->texturePath() != TEXTURE_PATHS[FLAG])
                    {
                        temp->texturePath() = TEXTURE_PATHS[FLAG];
                    }
                    else
                    {
                        temp->texturePath() = TEXTURE_PATHS[UNCHECKED];
                    }
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
