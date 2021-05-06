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

const string ASSET_DIR = "assets/";
const string TEXTURE_PATHS[] = {
    "EmptyCell.png",
    "One.png",
    "Two.png",
    "Three.png",
    "Four.png",
    "Five.png",
    "Six.png",
    "Seven.png",
    "Eight.png",
    "UnCheckedCell.png",
    "ExplodedMine.png",
    "Mine.png",
    "NotAMine.png",
    "Flag.png"
};

enum TexturePathIndices{
    EMPTY=0,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    UNCHECKED,
    EXPLODED,
    MINE,
    NOTMINE,
    FLAG
};

class BaseRect
{
    protected:
        sf::RectangleShape mRect;
        sf::Texture mTexture;
        string mTexturePath;
        int mRectWidth, mRectHeight;

    public:
        // BaseRect(int x=0, int y=0, string path=TEXTURE_PATHS[UNCHECKED]);
        virtual sf::Texture& getTexture();
        // virtual void setRectTexture(string path);
        virtual string& texturePath();
        // virtual void setTexturePath(string path);
        virtual sf::RectangleShape& getShape();

        virtual int& rectWidth();
        virtual int& rectHeight();

};

#endif