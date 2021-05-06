/**
 * @file game.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief game class function file
 * @date 2021-05-03
 * 
 */
#include <SFML/Graphics.hpp>

#include "cell.h"
#include "board.h"
#include "game.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 * @param width width of new window
 * @param height height of new window
 * @param cellSize size of game board cells
 */
Game::Game(int width, int height, int cellSize) : mWindow(sf::VideoMode(width * cellSize, height * cellSize), "Minesweeper"),
                                                  mBoard(width, height)
{
    mWindowHeight = height;
    mWindowWidth = width;
    mCellSize = cellSize;
    mIsWon = false; // assume victory
}

/**
 * @brief Launch the game's difficulty menu prior to the actual game
 * 
 */
void Game::menu()
{
    mWindowHeight = 10;
    mWindowWidth = 10;

    //This resizing code was taken from SFML team member eXpl0it3r on the sfml-dev.org forums.
    //Credit goes to them for the following 7 lines 
    sf::View view = mWindow.getView();
    sf::Vector2f size = static_cast<sf::Vector2f>(mWindow.getSize());
    size = (sf::Vector2f(mWindowWidth * mCellSize, mWindowHeight * mCellSize));
    view.setCenter(size/2.f);
    view.setSize(size);
    mWindow.setSize(static_cast<sf::Vector2<unsigned int> >(size));
    mWindow.setView(sf::View(sf::FloatRect(0.f, 0.f, size.x, size.y)));

    mBoard.setGameStatus(false);

    sf::Text title;
    sf::Font font;

    //Credit - Nasa21 font by USE Mediengestaltung of Berlin
    font.loadFromFile("assets/title.ttf");
    
    title.setFont(font);
    title.move(65, 10);
    title.setString("MINESWEEPER");
    title.setCharacterSize(26);
    title.setFillColor(sf::Color::Red);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RectangleShape shape1(sf::Vector2f(100.0f, 40.0f));
    sf::Texture texture1;
    texture1.loadFromFile("assets/EasyButton.png");
    shape1.setTexture(&texture1);
    shape1.setPosition(100, 65);

    sf::RectangleShape shape2(sf::Vector2f(100.0f, 40.0f));
    sf::Texture texture2;
    texture2.loadFromFile("assets/MediumButton.png");
    shape2.setTexture(&texture2);
    shape2.setPosition(100, 145);

    sf::RectangleShape shape3(sf::Vector2f(100.0f, 40.0f));
    sf::Texture texture3;
    texture3.loadFromFile("assets/HardButton.PNG");
    shape3.setTexture(&texture3);
    shape3.setPosition(100, 225);

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
                        run(8, 10, 10);
                    }
                    if (shape2.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        run(14, 18, 40);
                    }
                    if (shape3.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        run(20, 24, 99);
                    }
                }
            }
        }
        mWindow.clear(sf::Color::White);
        mWindow.draw(title);
        mWindow.draw(shape1);
        mWindow.draw(shape2);
        mWindow.draw(shape3);
        mWindow.display();
    }
}

/**
 * @brief Launches the actual game with the given parameters
 * 
 * @param width width of the board
 * @param height height of the board
 * @param mines number of mines
 */
void Game::run(int width, int height, int mines)
{
    mWindowWidth = width;
    mWindowHeight = height;
    mBoard.setMines(mines);
    mBoard.setNumFlags(mines); // flags is the same number of mines
    mBoard.setSize(width, height);

    //This resizing code was taken from SFML team member eXpl0it3r on the sfml-dev.org forums.
    //Credit goes to them for the following 7 lines 
    sf::View view = mWindow.getView();
    sf::Vector2f size = static_cast<sf::Vector2f>(mWindow.getSize());
    size = (sf::Vector2f(mWindowWidth * mCellSize, mWindowHeight * mCellSize));
    view.setCenter(size/2.f);
    view.setSize(size);
    mWindow.setSize(static_cast<sf::Vector2<unsigned int> >(size));
    mWindow.setView(sf::View(sf::FloatRect(0.f, 0.f, size.x, size.y)));

    sf::Text prompt;
    sf::Font font;

    // //Credit - Nasa21 font by USE Mediengestaltung of Berlin
    // font.loadFromFile("assets/title.ttf");

    // prompt.setFont(font);
    // prompt.setString("GAME OVER");
    // prompt.setCharacterSize(30);
    // prompt.setFillColor(sf::Color::Blue);
    // prompt.setStyle(sf::Text::Bold | sf::Text::Underlined);
    // prompt.setOutlineColor(sf::Color::Black);
    // prompt.setOutlineThickness(3.0f);

    // prompt.setPosition(((mWindow.getSize().x) - prompt.getGlobalBounds().width) / 2, mWindowHeight / 2);

    sf::Event event;

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
                    if (mBoard.getGameStatus()) // if game over, restart at first left click
                    {
                        menu();
                    }
                    else
                    {
                        mBoard.checkCell(mouseX, mouseY);
                        // mIsWon = mBoard.checkConditions();
                        // if (mIsWon)
                        // {
                        //     mBoard.setGameStatus(true);
                        // }
                    }
                }

                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    Cell *cellPtr = &mBoard.getCell(mouseX, mouseY);
                    if(!mBoard.noFlags()) // if player still has flagss
                    {
                        if (cellPtr->texturePath() == TEXTURE_PATHS[UNCHECKED]) // if cell is unchecked
                        {
                            cellPtr->texturePath() = TEXTURE_PATHS[FLAG]; // add flag to board
                            mBoard.subtractFlag(); // subtract flag from player's number of usable flags
                        }
                        else if (cellPtr->texturePath() == TEXTURE_PATHS[FLAG]) // if cell is flagged
                        {
                            cellPtr->texturePath() = TEXTURE_PATHS[UNCHECKED]; // remove flag
                            mBoard.addFlag(); // add flag to player's number of usable flags
                        }
                    }
                    else if (cellPtr->texturePath() == TEXTURE_PATHS[FLAG]) // if player has no flags left and cell is flagged
                    {
                        cellPtr->texturePath() = TEXTURE_PATHS[UNCHECKED];
                        // temp->texturePath() = TEXTURE_PATHS[UNCHECKED]; // remove flag
                        mBoard.addFlag(); // add flag to player's number of usable flags
                    }
                }
            }
        }
        mWindow.clear();

        // sf::Sprite sprite;
        // sf::RectangleShape sprite;
        // sprite.setOutlineThickness(.1f);
        // sprite.setOutlineColor(sf::Color::Black);
        // sprite.setSize(sf::Vector2f(mCellSize, mCellSize));
        // sprite.setScale(sf::Vector2f(.4, .4));
        sf::Texture texture;
        texture.setSmooth(true);
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(mCellSize, mCellSize));

        for (int y = 0; y < mWindowHeight; ++y)
        {
            for (int x = 0; x < mWindowWidth; ++x)
            {
                Cell *cellPtr = &mBoard.getCell(x, y);
                texture.loadFromFile(ASSET_DIR + cellPtr->texturePath());
                rect.setPosition(sf::Vector2f(x * mCellSize, y * mCellSize));
                rect.setTexture(&texture);
                cellPtr->getShape().setPosition(sf::Vector2f(x * mCellSize, y * mCellSize));
                mWindow.draw(rect);
            }
        }

        if (mBoard.getGameStatus())
        {
                //Credit - Nasa21 font by USE Mediengestaltung of Berlin
            font.loadFromFile("assets/title.ttf");

            prompt.setFont(font);
            prompt.setString("GAME OVER");
            prompt.setCharacterSize(30);
            prompt.setFillColor(sf::Color::Blue);
            prompt.setStyle(sf::Text::Bold | sf::Text::Underlined);
            prompt.setOutlineColor(sf::Color::Black);
            prompt.setOutlineThickness(3.0f);

            prompt.setPosition(((mWindow.getSize().x) - prompt.getGlobalBounds().width) / 2, mWindowHeight / 2);
            // if (mIsWon)
            // {
            //     prompt.setString("YOU WIN!!!");
            //     prompt.setFillColor(sf::Color::Green);
            // }
            
            mWindow.draw(prompt);
        }
        
        mWindow.display();
    }
}