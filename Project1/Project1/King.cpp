#include"King.h"

King::King(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 1)
	{
		setCamp(false);		//black
	}
	else if (type == 8)
	{
		setCamp(true);		//red
	}
}

bool King::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if ((dest_x != nowx && dest_y != nowy) || (dest_x == nowx && (dest_y > nowy + 1 || dest_y < nowy - 1) || (dest_y == nowy && (dest_x > nowx + 1 || dest_x < nowx - 1))		//illegal moving
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
	if (dest_x == nowx && dest_y == nowy + 1)		//move down side
	{
		if (!getCamp())		//black					//confined to the nine point fortress
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
	if (dest_x == nowx && dest_y == nowy - 1)		//move up side
	{
		if (!getCamp())		//black					//confined to the nine point fortress
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
	if (dest_x == nowx + 1 && dest_y == nowy)		//move right side
	{
		if (dest_x > 5 || dest_x < 3)				//confined to the nine point fortress
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy)		//move left side
	{
		if (dest_x > 5 || dest_x < 3)				//confined to the nine point fortress
		{
			return 0;
		}
		return 1;
	}
}

bool King::kingMeetKing(King& enemyKing,const int *board[])		//king meet king
{
	if (getx() == enemyKing.getx())
	{
		for (int loop = gety() > enemyKing.gety() ? enemyKing.gety() + 1 : gety() + 1; loop < gety() > enemyKing.gety() ? gety() : enemyKing.gety(); loop++)
		{
			if (board[getx()][loop] != 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}