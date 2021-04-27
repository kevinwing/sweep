/**
 * @file rect.h
 * @author Connor McElroy, Caleb Simmons, Kevin Wing
 * @brief Abstract class for all rectangle shapes
 * @date 2021-04-21
 */
#ifndef RECT_H
#define RECT_H

#include <SFML/Graphics.hpp>
#include <string>

using std::string;

class BaseRect
{
    protected:
        string mPath;

    public:
        virtual sf::Texture& getTexturePath() = 0;

};

#endif