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
		camp = false;		//��
	}
	else if (type == 10)
	{
		camp = true;		//��
	}
	moveCount = 0;			//�H�b�������ʮɭp��
}

Elephant::~Elephant() {}

void Elephant::move(int dest_x, int dest_y)
{
	int board[9][10] = { 0 };
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//���s��J�ت��a
	}
	if ((dest_x != nowx + 2 && dest_x != nowx - 2) || (dest_y != nowy + 2 && dest_y != nowy - 2))	//���ŦX�H�����k
	{
		//���s��J�ت��a
	}
	if (dest_x == nowx + 2 && dest_y == nowy + 2)	//�k�U����
	{
		if (moveCount == 2 && !camp)				//�H���L�e
		{
			//you shall not pass
		}
		else if (0/*�ؼЦ�m���ͭx�Ѥl*/)
		{
			//you shall not pass
		}
		else if (board[nowx + 1][nowy + 1] != 0)	//��H��
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//�¤�
			{
				moveCount++;
				board[dest_x][dest_y] = 3;
			}
			else						//����
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
	if (dest_x == nowx - 2 && dest_y == nowy + 2)	//���U����
	{
		if (moveCount == 2 && !camp)				//�H���L�e
		{
			//you shall not pass
		}
		else if (0/*�ؼЦ�m���ͭx�Ѥl*/)
		{
			//you shall not pass
		}
		else if (board[nowx - 1][nowy + 1] != 0)	//��H��
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//�¤�
			{
				moveCount++;
				board[dest_x][dest_y] = 3;
			}
			else						//����
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
	if (dest_x == nowx + 2 && dest_y == nowy - 2)	//�k�W����
	{
		if (moveCount == 2 && camp)					//�H���L�e
		{
			//you shall not pass
		}
		else if (0/*�ؼЦ�m���ͭx�Ѥl*/)
		{
			//you shall not pass
		}
		else if (board[nowx + 1][nowy - 1] != 0)	//��H��
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//�¤�
			{
				moveCount--;
				board[dest_x][dest_y] = 3;
			}
			else						//����
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
	if (dest_x == nowx - 2 && dest_y == nowy - 2)	//���W����
	{
		if (moveCount == 2 && camp)					//�H���L�e
		{
			//you shall not pass
		}
		else if (0/*�ؼЦ�m���ͭx�Ѥl*/)
		{
			//you shall not pass
		}
		else if (board[nowx - 1][nowy - 1] != 0)	//��H��
		{
			//you shall not pass
		}
		else
		{
			board[nowx][nowy] = 0;
			if (!camp)					//�¤�
			{
				moveCount--;
				board[dest_x][dest_y] = 3;
			}
			else						//����
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