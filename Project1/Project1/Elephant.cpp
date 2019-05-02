#include"Elephant.h"

Elephant::Elephant(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 3)
	{
		setCamp(false);		//��
	}
	else if (type == 10)
	{
		setCamp(true);		//��
	}
	moveCount = 0;			//�H�b�������ʮɭp��
}

bool Elephant::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
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
	if (board[dest_x][dest_y] != 0)				//�P�_�ؼЦ�m�O���O�ͭx
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
	if (dest_x == nowx + 2 && dest_y == nowy + 2)	//�k�U����
	{
		if (moveCount == 2 && !getCamp())			//�H���L�e
		{
			return 0;
		}
		if (board[nowx + 1][nowy + 1] != 0)			//��H��
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//�¤�
			{
				moveCount++;
			}
			else									//����
			{
				moveCount--;
			}
			return 1;
		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 2)	//���U����
	{
		if (moveCount == 2 && !getCamp())			//�H���L�e
		{
			return 0;
		}
		if (board[nowx - 1][nowy + 1] != 0)			//��H��
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//�¤�
			{
				moveCount++;
			}
			else									//����
			{
				moveCount--;
			}
			return 1;
		}
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 2)	//�k�W����
	{
		if (moveCount == 2 && getCamp())			//�H���L�e
		{
			return 0;
		}
		if (board[nowx + 1][nowy - 1] != 0)			//��H��
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//�¤�
			{
				moveCount--;
			}
			else									//����
			{
				moveCount++;
			}
			return 1;
		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 2)	//���W����
	{
		if (moveCount == 2 && getCamp())			//�H���L�e
		{
			return 0;
		}
		if (board[nowx - 1][nowy - 1] != 0)			//��H��
		{
			return 0;
		}
		else
		{
			if (!getCamp)							//�¤�
			{
				moveCount--;
			}
			else									//����
			{
				moveCount++;
			}
			return 1;
		}
	}
}