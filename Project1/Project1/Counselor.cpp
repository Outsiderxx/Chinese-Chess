#include"Counselor.h"

Counselor::Counselor(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 2)
	{
		setCamp(false);		//��
	}
	else if (type == 9)
	{
		setCamp(true);		//��
	}
}

bool Counselor::isMovable(int dest_x, int dest_y, const int *board[])
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//���s��J�ت��a
		return 0;
	}
	if ((dest_x != nowx + 1 && dest_x != nowx - 1) || (dest_y != nowy + 1 && dest_y != nowy - 1))	//���ŦX�h�����k
	{
		//���s��J�ت��a
		return 0;
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
	if (dest_x == nowx + 1 && dest_y == nowy + 1)		//�k�U����
	{
		if (dest_x > 5 || dest_x < 3)					//���X�E�c��
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
	if (dest_x == nowx - 1 && dest_y == nowy + 1)		//���U����
	{
		if (dest_x > 5 || dest_x < 3)					//���X�E�c��
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
	if (dest_x == nowx + 1 && dest_y == nowy - 1)		//�k�W����
	{
		if (dest_x > 5 || dest_x < 3)					//���X�E�c��
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
	if (dest_x == nowx - 1 && dest_y == nowy - 1)		//���U����
	{
		if (dest_x > 5 || dest_x < 3)					//���X�E�c��
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