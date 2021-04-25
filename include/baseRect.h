/**
 * @file rect.h
 * @author Connor McElroy, Caleb Simmons, Kevin Wing
 * @brief Abstract class for all rectangle shapes
 * @date 2021-04-21
 */
#ifndef RECT_H
#define RECT_H

#include <SFML/Graphics.hpp>

class BaseRect
{
    protected:
        sf::RectangleShape rectShape;
        sf::Texture texture;

    public:
        virtual sf::RectangleShape& getShape() = 0;

};

#endif