#include "slave.h"

slave::slave(){}
slave::slave(int nowx, int nowy, int type)
{
	setx(nowx);
	sety(nowy);
	if (type == 7) //black
	{
		camp = false;
	}
	else if(type == 14) //red
	{
		camp = true;
	}
}
slave::~slave(){}
void slave::move(int dest_x,int dest_y)
{
	bool passRiverOrNot = false;
	int nowx = getx();
	int nowy = gety();
	int board[9][10] = { 0 }; //���]���ѽL �����main�̪�
	if (dest_x == nowx && dest_y == nowy) //���ʨ��� ���s����
	{
		//���s��J�ت��a
	}
	if (!camp)  // black
	{
		if (nowy >= 5) passRiverOrNot = true;
		if (dest_y < nowy) //�򤣫�h
		{
			//���s��J�ت��a
		}
		if (!passRiverOrNot) //���L�e�������k
		{
			if (dest_x != nowx)
			{
				//���s��J�ت��a
			}
		}
		//�����H�W���� �h�N���ಾ��
		board[nowx][nowy] = 0;
		board[dest_x][dest_y] = 7;
		setx(dest_x);
		sety(dest_y);
	}
	else		// red
	{
		if (nowy <= 4) passRiverOrNot = true;
		if (dest_y > nowy) //�򤣫�h
		{
			//���s��J�ت��a
		}
		if (!passRiverOrNot) //���L�e�������k
		{
			if (dest_x != nowx)
			{
				//���s��J�ت��a
			}
		}
		board[nowx][nowy] = 0;
		board[dest_x][dest_y] = 14;
		setx(dest_x);
		sety(dest_y);
	}
}
