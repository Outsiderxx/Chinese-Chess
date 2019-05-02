#pragma once
#include"chessBasic.h"
class slave:public chessBasic
{
public:
	slave();
	slave(int, int, int);
	~slave();
	bool isMovable(int, int, vector<vector<int> >);
};

