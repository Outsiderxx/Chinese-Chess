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
	int board[9][10] = { 0 }; //assume the initial board

	if (dest_x == nowx && dest_y == nowy) //move to the original position.
	{
		//move again.
	}
	if (!camp)  // black
	{
		if (nowy >= 5) passRiverOrNot = true;
		if (dest_y < nowy) //slave cannot go back.
		{
			//move again.
		}
		if (!passRiverOrNot) //slave cannot go left or right before pass the river.
		{
			if (dest_x != nowx)
			{
				//move again.
			}
		}
		//satisfy the upper condition, slave can move.
		if (board[dest_x][dest_y] != 0) // if this move is eat other chess
		{
			//setting other chess's status.
		}
		board[nowx][nowy] = 0;
		board[dest_x][dest_y] = 7;
		setx(dest_x);
		sety(dest_y);
	}
	else		// red
	{
		if (nowy <= 4) passRiverOrNot = true;
		if (dest_y > nowy) //slave cannot go back.
		{
			//move again.
		}
		if (!passRiverOrNot) //slave cannot go left or right before pass the river.
		{
			if (dest_x != nowx)
			{
				//move again.
			}
		}
		//satisfy the upper condition, slave can move.
		if (board[dest_x][dest_y] != 0) // if this move is eat other chess
		{
			//setting other chess's status.
		}
		board[nowx][nowy] = 0;
		board[dest_x][dest_y] = 14;
		setx(dest_x);
		sety(dest_y);
	}
}
