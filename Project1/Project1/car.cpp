#include "car.h"
#include<iostream>
car::car() {}
car::car(int nowx, int nowy)
{
	setx(nowx);
	sety(nowy);
}

car::~car() {}

void car::move(int dest_x, int dest_y)
{
	int nowx = getx();
	int nowy = gety();
	int board[9][10] = { 0 }; //assume the initial board
	if (dest_x == nowx && dest_y == nowy) //move to the original position.
	{
		//move again.
	}
	if (((dest_x == nowx) && (dest_y != nowy)) || ((dest_x != nowx) && (dest_y == nowy))) //destnation should be car's row or column, or move again.
	{
		if ((dest_x == nowx) && (dest_y != nowy)) //move in a column.
		{
			int distance = dest_y - nowy;
			bool obstacle = false;
			if (distance < 0) //go up.
			{
				for (int i = nowy - 1; i > dest_y; --i)
				{
					if (board[dest_x][i] != 0)
					{
						obstacle = true;
						break;
					}
				}
				if (obstacle)
				{
					//move again.
					int A;
				}
				else
				{
					
					board[nowx][nowy] = 0;
					board[dest_x]
				}

			}
			else if (distance > 0) //go down.
			{

			}
		}
		else if ((dest_x != nowx) && (dest_y == nowy)) //move in a row.
		{
			if (dest_x < nowx) //go left.
			{

			}
			else if (dest_x > nowx) //go right.
			{

			}
		}
		else //prevent the exceptional condition.
		{
			std::cout << "exceptional condition in car.cpp" << endl;
			//move again.
		}
	}
	else
	{
		//move again.
	}
}
