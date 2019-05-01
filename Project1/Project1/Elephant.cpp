#include"Elephant.h"
#include<iostream>
#include<iomanip>
using namespace std;
Elephant::Elephant() {}

Elephant::Elephant(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 3)
	{
		camp = false;		//黑
	}
	else if (type == 10)
	{
		camp = true;		//紅
	}
	moveCount = 0;			//象在垂直移動時計數
}

Elephant::~Elephant() {}

void Elephant::move(int dest_x, int dest_y)
{
	int board[9][10] = { 0 };
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
	if (dest_x == nowx + 2 && dest_y == nowy + 2)	//右下移動
	{
		if (moveCount == 2 && !camp)				//象不過河
		{
			//you shall not pass
		}
		else if (0/*目標位置有友軍棋子*/)
		{
			//you shall not pass
		}
		else if (board[nowx + 1][nowy + 1] != 0)	//塞象眼
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//黑方
			{
				moveCount++;
				board[dest_x][dest_y] = 3;
			}
			else						//紅方
			{
				moveCount--;
				board[dest_x][dest_y] = 10;
			}
			setx(dest_x);
			sety(dest_y);



			for (int loop = 0; loop < 10; loop++)
			{
				for (int loop1 = 0; loop1 < 9; loop1++)
				{
					cout << setw(3) << board[loop1][loop];
				}
				cout << endl;
			}



		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 2)	//左下移動
	{
		if (moveCount == 2 && !camp)				//象不過河
		{
			//you shall not pass
		}
		else if (0/*目標位置有友軍棋子*/)
		{
			//you shall not pass
		}
		else if (board[nowx - 1][nowy + 1] != 0)	//塞象眼
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//黑方
			{
				moveCount++;
				board[dest_x][dest_y] = 3;
			}
			else						//紅方
			{
				moveCount--;
				board[dest_x][dest_y] = 10;
			}
			setx(dest_x);
			sety(dest_y);



			for (int loop = 0; loop < 10; loop++)
			{
				for (int loop1 = 0; loop1 < 9; loop1++)
				{
					cout << setw(3) << board[loop1][loop];
				}
				cout << endl;
			}



		}
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 2)	//右上移動
	{
		if (moveCount == 2 && camp)					//象不過河
		{
			//you shall not pass
		}
		else if (0/*目標位置有友軍棋子*/)
		{
			//you shall not pass
		}
		else if (board[nowx + 1][nowy - 1] != 0)	//塞象眼
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//黑方
			{
				moveCount--;
				board[dest_x][dest_y] = 3;
			}
			else						//紅方
			{
				moveCount++;
				board[dest_x][dest_y] = 10;
			}
			setx(dest_x);
			sety(dest_y);



			for (int loop = 0; loop < 10; loop++)
			{
				for (int loop1 = 0; loop1 < 9; loop1++)
				{
					cout << setw(3) << board[loop1][loop];
				}
				cout << endl;
			}



		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 2)	//左上移動
	{
		if (moveCount == 2 && camp)					//象不過河
		{
			//you shall not pass
		}
		else if (0/*目標位置有友軍棋子*/)
		{
			//you shall not pass
		}
		else if (board[nowx - 1][nowy - 1] != 0)	//塞象眼
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//黑方
			{
				moveCount--;
				board[dest_x][dest_y] = 3;
			}
			else						//紅方
			{
				moveCount++;
				board[dest_x][dest_y] = 10;
			}
			setx(dest_x);
			sety(dest_y);



			for (int loop = 0; loop < 10; loop++)
			{
				for (int loop1 = 0; loop1 < 9; loop1++)
				{
					cout << setw(3) << board[loop1][loop];
				}
				cout << endl;
			}



		}
	}
}