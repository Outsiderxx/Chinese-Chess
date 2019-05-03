#pragma once
#include"chessBasic.h"
class car : public chessBasic
{
public:
	car();
	car(int, int, int);
	~car();
	bool isMovable(int, int, vector< vector<int> >);
};

