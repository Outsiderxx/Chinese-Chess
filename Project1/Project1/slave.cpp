#include "slave.h"

slave::slave(){}
slave::slave(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 7) //black
	{
		camp = false;
	}
	else if(type == 14) //red
	{
		camp = true;
	}
}
slave::~slave(){}
void slave::move(int dest_x,int dest_y)
{
	bool passRiverOrNot = false;
	int nowx = getx();
	int nowy = gety();
	int board[9][10] = { 0 }; //假設的棋盤 之後用main裡的
	if (dest_x == nowx && dest_y == nowy) //移動到原位 重新移動
	{
		//重新輸入目的地
	}
	if (!camp)  // black
	{
		if (nowy >= 5) passRiverOrNot = true;
		if (dest_y < nowy) //卒不後退
		{
			//重新輸入目的地
		}
		if (!passRiverOrNot) //未過河不走左右
		{
			if (dest_x != nowx)
			{
				//重新輸入目的地
			}
		}
		//滿足以上條件 則代表卒能移動
		board[nowx][nowy] = 0;
		board[dest_x][dest_y] = 7;
		setx(dest_x);
		sety(dest_y);
	}
	else		// red
	{
		if (nowy <= 4) passRiverOrNot = true;
		if (dest_y > nowy) //卒不後退
		{
			//重新輸入目的地
		}
		if (!passRiverOrNot) //未過河不走左右
		{
			if (dest_x != nowx)
			{
				//重新輸入目的地
			}
		}
		board[nowx][nowy] = 0;
		board[dest_x][dest_y] = 14;
		setx(dest_x);
		sety(dest_y);
	}
}
