#pragma once
#include<iostream>
using namespace std;
class chessBasic
{
public:
	bool getstatus();
	void setx(int);
	void sety(int);
	int getx();
	int gety();

private:
	bool status;
	int x;
	int y;
};



