#include"Counselor.h"

Counselor::Counselor(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 2)
	{
		setCamp(false);		//black
	}
	else if (type == 9)
	{
		setCamp(true);		//red
	}
}

bool Counselor::isMovable(int dest_x, int dest_y, vector<vector<int >> board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if ((dest_x != nowx + 1 && dest_x != nowx - 1) || (dest_y != nowy + 1 && dest_y != nowy - 1))	//illegal moving
	{
		//move again
		return 0;
	}
	if (board[dest_x][dest_y] != 0)				//same camp
	{
		if (board[dest_x][dest_y] <= 7 && !getCamp())
		{
			return 0;
		}
		if (board[dest_x][dest_y] > 7 && getCamp())
		{
			return 0;
		}
	}
	if (dest_x == nowx + 1 && dest_y == nowy + 1)		//move right down
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
		{
			return 0;
		}
		if (!getCamp())		//black
		{
			if (dest_y > 2)
			{
				return 0;
			}
		}
		else				//red
		{
			if (dest_y < 7)
			{
				return 0;
			}
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy + 1)		//move left down
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
		{
			return 0;
		}
		if (!getCamp())		//black
		{
			if (dest_y > 2)
			{
				return 0;
			}
		}
		else				//red
		{
			if (dest_y < 7)
			{
				return 0;
			}
		}
		return 1;
	}
	if (dest_x == nowx + 1 && dest_y == nowy - 1)		//move right up
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
		{
			return 0;
		}
		if (!getCamp())		//black
		{
			if (dest_y > 2)
			{
				return 0;
			}
		}
		else				//red
		{
			if (dest_y < 7)
			{
				return 0;
			}
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy - 1)		//move left down
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
		{
			return 0;
		}
		if (!getCamp())		//black
		{
			if (dest_y > 2)
			{
				return 0;
			}
		}
		else				//red
		{
			if (dest_y < 7)
			{
				return 0;
			}
		}
		return 1;
	}
}