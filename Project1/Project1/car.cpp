#include "car.h"
#include<vector>
car::car() {}
car::car(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 7) //black
	{
		setCamp(false);
	}
	else if (type == 14) //red
	{
		setCamp(true);
	}
}
car::~car() {}
bool car::isMovable(int dest_x, int dest_y, const int *board[])
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy) //move to the original position.
	{
		//move again.
		return 0;
	}
	if (((dest_x == nowx) && (dest_y != nowy)) || ((dest_x != nowx) && (dest_y == nowy))) //destnation should be car's row or column, or move again.
	{
		if ((dest_x == nowx) && (dest_y != nowy)) //move in a column.
		{
			bool obstacle = false;
			if (dest_y < nowy) //go up.
			{
				for (int i = nowy - 1; i > dest_y; --i)
				{
					if (board[dest_x][i] != 0)
					{
						obstacle = true;
						break;
					}
				}
				if (obstacle) //there are some obstacle between car and its destnation.
				{
					//move again.
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else if (dest_y > nowy) //go down.
			{
				for (int i = nowy + 1; i < dest_y; ++i)
				{
					if (board[dest_x][i] != 0)
					{
						obstacle = true;
						break;
					}
				}
				if (obstacle) //there are some obstacle between car and its destnation.
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		else if ((dest_x != nowx) && (dest_y == nowy)) //move in a row.
		{
			bool obstacle = false;
			if (dest_x < nowx) //go left.
			{
				for (int i = nowx - 1; i > dest_x; --i)
				{
					if (board[i][dest_y] != 0)
					{
						obstacle = true;
						break;
					}
					if (obstacle) //there are some obstacle between car and its destnation.
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}
			else if (dest_x > nowx) //go right.
			{
				for (int i = nowx + 1; i < dest_x; ++i)
				{
					if (board[i][dest_y] != 0)
					{
						obstacle = true;
						break;
					}
					if (obstacle) //there are some obstacle between car and its destnation.
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}
		}
		else //prevent the exceptional condition.
		{
			//move again.
			return 0;
		}
	}
	else
	{
		//move again.
		return 0;
	}
}
