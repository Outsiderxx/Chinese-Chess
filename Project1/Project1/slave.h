#pragma once
#include"chessBasic.h"
class slave:public chessBasic
{
public:
	slave();
	slave(int, int, int);
	~slave();
	void move(int, int);
private:
	bool camp; // 0 = black , 1 = red
};

