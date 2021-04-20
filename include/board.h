/**
 * @file board.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEMPLATE_H
#define TEMPLATE_H

class Board
{
public:
	Board(int mines, int width, int height);
	~Board();
	void print();
private:
	const int mines;
    const int width;
    const int height;
};

#endif