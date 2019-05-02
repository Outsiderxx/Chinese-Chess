#include"King.h"

King::King(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 1)
	{
		setCamp(false);		//黑
	}
	else if (type == 8)
	{
		setCamp(true);		//紅
	}
}

bool King::isMovable(int dest_x, int dest_y, const int *board[])
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//重新輸入目的地
		return 0;
	}
	if (dest_x > nowx + 1 || dest_x < nowx - 1 || dest_y > nowy + 1 || dest_y < nowy - 1)		//不符合將的走法
	{
		//重新輸入目的地
		return 0;
	}
	if (board[dest_x][dest_y] != 0)				//判斷目標位置是不是友軍
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
	if (dest_x == nowx && dest_y == nowy + 1)		//向下移動
	{
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
	if (dest_x == nowx && dest_y == nowy - 1)		//向上移動
	{
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
	if (dest_x == nowx + 1 && dest_y == nowy)		//向右移動
	{
		if (dest_x > 5 || dest_x < 3)				//不出九宮格
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy)		//向左移動
	{
		if (dest_x > 5 || dest_x < 3)				//不出九宮格
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 1 && dest_y == nowy + 1)		//右下移動
	{
		if (dest_x > 5 || dest_x < 3)					//不出九宮格
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
	if (dest_x == nowx - 1 && dest_y == nowy + 1)		//左下移動
	{
		if (dest_x > 5 || dest_x < 3)					//不出九宮格
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
	if (dest_x == nowx + 1 && dest_y == nowy - 1)		//右上移動
	{
		if (dest_x > 5 || dest_x < 3)					//不出九宮格
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
	if (dest_x == nowx - 1 && dest_y == nowy - 1)		//左下移動
	{
		if (dest_x > 5 || dest_x < 3)					//不出九宮格
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

bool King::kingMeetKing(King& enemyKing,const int *board[])		//判斷王見王
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