#include"King.h"

King::King(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 1)
	{
		setCamp(false);		//��
	}
	else if (type == 8)
	{
		setCamp(true);		//��
	}
}

bool King::isMovable(int dest_x, int dest_y, const int *board[])
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//���s��J�ت��a
		return 0;
	}
	if (dest_x > nowx + 1 || dest_x < nowx - 1 || dest_y > nowy + 1 || dest_y < nowy - 1)		//���ŦX�N�����k
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
	if (dest_x == nowx && dest_y == nowy + 1)		//�V�U����
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
	if (dest_x == nowx && dest_y == nowy - 1)		//�V�W����
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
	if (dest_x == nowx + 1 && dest_y == nowy)		//�V�k����
	{
		if (dest_x > 5 || dest_x < 3)				//���X�E�c��
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy)		//�V������
	{
		if (dest_x > 5 || dest_x < 3)				//���X�E�c��
		{
			return 0;
		}
		return 1;
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

bool King::kingMeetKing(King& enemyKing,const int *board[])		//�P�_������
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