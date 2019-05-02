#include "slave.h"

slave::slave(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 7)
	{
		setCamp(false);
	}
	else if (type == 14)
	{
		setCamp(true);
	}
}
bool slave::isMovable(int dest_x, int dest_y)
{
	bool passRiverOrNot = false;
	int nowx = getx();
	int nowy = gety();
	int board[9][10] = { 0 }; //���]���ѽL �����main�̪�
	if (dest_x == nowx && dest_y == nowy) //���ʨ��� ��è
	{
		//���s��J�ت��a
	}
	if (!getCamp())  // black
	{
		if (nowy >= 5) passRiverOrNot = true;
		if (dest_y < nowy) //�򤣫�h
		{
			return 0;
		}
		if (!passRiverOrNot) //���L�e�������k
		{
			if (dest_x != nowx)
			{
				return 0;
			}
		}
		return 1;
	}
	else		// red
	{
		if (nowy <= 4) passRiverOrNot = true;
	}
}