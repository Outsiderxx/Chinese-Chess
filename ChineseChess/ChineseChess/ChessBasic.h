#pragma once
#include<iostream>
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
	virtual bool isMovable() = 0;
private:
	int x, y;
	bool camp;
};