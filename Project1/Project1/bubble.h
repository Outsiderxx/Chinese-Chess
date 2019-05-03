#pragma once
#include"chessBasic.h"
class bubble : public chessBasic
{
public:
	bubble();
	bubble(int, int, int);
	~bubble();
	bool isMovable(int, int, vector<vector<int>>);
};

