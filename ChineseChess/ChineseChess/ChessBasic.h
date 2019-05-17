#pragma once
#include <iostream>
#include <vector>
using namespace std;

class chessBasic
{
public:
	void setx(int);
	void sety(int);
	int getx();
	int gety();
	void setCamp(bool);
	bool getCamp();
	virtual bool isMovable(int, int, vector<vector<int>>) = 0;
	virtual vector<vector<bool>> hint(int, int, vector<vector<int>>) = 0;
private:
	int x, y;
	bool camp;
