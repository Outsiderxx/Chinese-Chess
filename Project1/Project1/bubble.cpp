#include "bubble.h"

bubble::bubble(){}
bubble::bubble(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 6) //black
	{
		setCamp(false);
	}
	else if (type == 13) //red
	{
		setCamp(true);
	}
}
bubble::~bubble(){}
bool bubble::isMovable(int dest_x, int dest_y, const int *board[])
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy) //move to the original position.
	{
		//move again.
		return 0;
	}
	if (!getCamp())
	{
		if (board[dest_x][dest_y] >= 1 && board[dest_x][dest_y] <= 7) { return 0; } //same camp in black
	}
	else
	{
		if (board[dest_x][dest_y] >= 8 && board[dest_x][dest_y] <= 14) { return 0; } //same camp in red
	}
	if (((dest_x == nowx) && (dest_y != nowy)) || ((dest_x != nowx) && (dest_y == nowy))) //destnation should be bubble's row or column, or move again.
	{
		if ((dest_x == nowx) && (dest_y != nowy)) //move in a column.
		{
			int obstacleCount = 0;
			if (dest_y < nowy) //go up.
			{
				for (int i = nowy - 1; i > dest_y; --i)
				{
					if (board[dest_x][i] != 0)
					{
						obstacleCount++;
					}
				}
				if (obstacleCount > 1) //there are too many obstacle between bubble and its destnation.
				{
					//move again.
					return 0;
				}
				else
				{
					if (obstacleCount == 1)
					{
						if (board[dest_x][dest_y] == 0) return 0; //no target to eat.
						else
						{
							return 1;
						}
					}
					else return 1;
				}
			}
			else if (dest_y > nowy) //go down.
			{
				for (int i = nowy + 1; i < dest_y; ++i)
				{
					if (board[dest_x][i] != 0)
					{
						obstacleCount++;
					}
				}
				if (obstacleCount > 1) //there are too many obstacle between bubble and its destnation.
				{
					return 0;
				}
				else
				{
					if (obstacleCount == 1)
					{
						if (board[dest_x][dest_y] == 0) return 0; //no target to eat.
						else
						{
							return 1;
						}
					}
					else return 1;
				}
			}
		}
		else if ((dest_x != nowx) && (dest_y == nowy)) //move in a row.
		{
			int obstacleCount = 0;
			if (dest_x < nowx) //go left.
			{
				for (int i = nowx - 1; i > dest_x; --i)
				{
					if (board[i][dest_y] != 0)
					{
						obstacleCount++;
					}
					if (obstacleCount > 1) //there are too many obstacle between bubble and its destnation.
					{
						return 0;
					}
					else
					{
						if (obstacleCount == 1)
						{
							if (board[dest_x][dest_y] == 0) return 0; //no target to eat.
							else
							{
								return 1;
							}
						}
						else return 1;
					}
				}
			}
			else if (dest_x > nowx) //go right.
			{
				for (int i = nowx + 1; i < dest_x; ++i)
				{
					if (board[i][dest_y] != 0)
					{
						obstacleCount++;
					}
					if (obstacleCount > 1) //there are too many obstacle between bubble and its destnation.
					{
						return 0;
					}
					else
					{
						if (obstacleCount == 1)
						{
							if (board[dest_x][dest_y] == 0) return 0; //no target to eat.
							else
							{
								return 1;
							}
						}
						else return 1;
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