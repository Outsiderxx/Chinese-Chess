#pragma once
#include"chessBasic.h"
class bubble : public chessBasic
{
public:
	bubble(void) {}
	bool isMovable(int, int, const vector<vector<int>>);
	vector<vector<bool> > hint(int, int, vector<vector<int> >);
};