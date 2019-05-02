#include"Counselor.h"

Counselor::Counselor(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 2)
	{
		setCamp(false);		//黑
	}
	else if (type == 9)
	{
		setCamp(true);		//紅
	}
}

bool Counselor::isMovable(int dest_x, int dest_y, const int *board[])
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//重新輸入目的地
		return 0;
	}
	if ((dest_x != nowx + 1 && dest_x != nowx - 1) || (dest_y != nowy + 1 && dest_y != nowy - 1))	//不符合士的走法
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