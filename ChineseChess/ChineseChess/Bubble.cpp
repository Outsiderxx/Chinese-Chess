#include "bubble.h"

bool bubble::isMovable(int dest_x, int dest_y, vector<vector<int>> board)
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
		if (board[dest_y][dest_x] >= 1 && board[dest_y][dest_x] <= 7) { return 0; } //same camp in black
	}
	else
	{
		if (board[dest_y][dest_x] >= 8 && board[dest_y][dest_x] <= 14) { return 0; } //same camp in red
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
					if (board[i][dest_x] != 0)
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
						if (board[dest_y][dest_x] == 0) return 0; //no target to eat.
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
					if (board[i][dest_x] != 0)
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
						if (board[dest_y][dest_x] == 0) return 0; //no target to eat.
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
					if (board[dest_y][i] != 0)
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
						if (board[dest_y][dest_x] == 0) return 0; //no target to eat.
						else
						{
							return 1;
						}
					}
					else return 1;
				}
			}
			else if (dest_x > nowx) //go right.
			{
				for (int i = nowx + 1; i < dest_x; ++i)
				{
					if (board[dest_y][i] != 0)
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
						if (board[dest_y][dest_x] == 0) return 0; //no target to eat.
						else
						{
							return 1;
						}
					}
					else return 1;
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