#include"Elephant.h"

Elephant::Elephant(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 3)
	{
		setCamp(false);		//黑
	}
	else if (type == 10)
	{
		setCamp(true);		//紅
	}
	moveCount = 0;			//象在垂直移動時計數
}

bool Elephant::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//重新輸入目的地
	}
	if ((dest_x != nowx + 2 && dest_x != nowx - 2) || (dest_y != nowy + 2 && dest_y != nowy - 2))	//不符合象的走法
	{
		//重新輸入目的地
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
	if (dest_x == nowx + 2 && dest_y == nowy + 2)	//右下移動
	{
		if (moveCount == 2 && !getCamp())			//象不過河
		{
			return 0;
		}
		if (board[nowx + 1][nowy + 1] != 0)			//塞象眼
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//黑方
			{
				moveCount++;
			}
			else									//紅方
			{
				moveCount--;
			}
			return 1;
		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 2)	//左下移動
	{
		if (moveCount == 2 && !getCamp())			//象不過河
		{
			return 0;
		}
		if (board[nowx - 1][nowy + 1] != 0)			//塞象眼
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//黑方
			{
				moveCount++;
			}
			else									//紅方
			{
				moveCount--;
			}
			return 1;
		}
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 2)	//右上移動
	{
		if (moveCount == 2 && getCamp())			//象不過河
		{
			return 0;
		}
		if (board[nowx + 1][nowy - 1] != 0)			//塞象眼
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//黑方
			{
				moveCount--;
			}
			else									//紅方
			{
				moveCount++;
			}
			return 1;
		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 2)	//左上移動
	{
		if (moveCount == 2 && getCamp())			//象不過河
		{
			return 0;
		}
		if (board[nowx - 1][nowy - 1] != 0)			//塞象眼
		{
			return 0;
		}
		else
		{
			if (!getCamp)							//黑方
			{
				moveCount--;
			}
			else									//紅方
			{
				moveCount++;
			}
			return 1;
		}
	}
}