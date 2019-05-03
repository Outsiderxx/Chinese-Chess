#include"Horse.h"

Horse::Horse(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 5)
	{
		setCamp(false);		//black
	}
	else if (type == 12)
	{
		setCamp(true);		//red
	}
}

bool Horse::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if (board[dest_x][dest_y] != 0)						//same camp
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
	if (dest_x == nowx + 2 && dest_y == nowy + 1)		//position 1 in horse.png
	{
		if (board[nowx + 1][nowy] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 1)		//position 2 in horse.png
	{
		if (board[nowx + 1][nowy] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 1 && dest_y == nowy - 2)		//position 3 in horse.png
	{
		if (board[nowx][nowy - 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy - 2)		//position 4 in horse.png
	{
		if (board[nowx][nowy - 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 1)		//position 5 in horse.png
	{
		if (board[nowx - 1][nowy] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 1)		//position 6 in horse.png
	{
		if (board[nowx - 1][nowy] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy + 2)		//position 7 in horse.png
	{
		if (board[nowx][nowy + 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 1 && dest_y == nowy + 2)		//position 8 in horse.png
	{
		if (board[nowx][nowy + 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	return 0;
}