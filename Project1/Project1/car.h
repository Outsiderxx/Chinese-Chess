#pragma once
#include"chessBasic.h"
class car:chessBasic
{
public:
	car();
	car(int, int, int);
	~car();
	bool isMovable(int, int,const int *board[]);
};

