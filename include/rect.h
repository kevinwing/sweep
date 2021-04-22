/**
 * @file rect.h
 * @author Connor McElroy, Caleb Simmons, Kevin Wing
 * @brief Abstract class for all rectangle shapes
 * @date 2021-04-21
 */
#ifndef RECT_H
#define RECT_H

class Rect
{
    protected:
        int mHeight;
        int mWidth;

    public:
        virtual int getHeight() = 0;
        virtual int getWidth() = 0;
        // Rect(int w=0, int h=0);
        // ~Rect();
};

#endif