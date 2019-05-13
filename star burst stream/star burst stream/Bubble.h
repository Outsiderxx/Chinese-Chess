#pragma once
#include"chessBasic.h"
class bubble : public chessBasic
{
public:
	bubble(void) {}
	virtual bool isMovable(int, int, const vector<vector<int>>);
	virtual vector<vector<bool>> hint(int, int, vector<vector<int>>);
};