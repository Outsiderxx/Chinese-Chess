#include "car.h"

car::car(){}
car::car(int nowx, int nowy)
{
	setx(nowx);
	sety(nowy);
}

car::~car(){}

void car::move(int dest_x, int dest_y)
{
	int nowx = getx();
	int nowy = gety();
	int board[9][10] = { 0 }; //���]���ѽL �����main�̪�
	if (dest_x == nowx && dest_y == nowy) //���ʨ��� ���s����
	{
		//���s��J�ت��a
	}
	if (((dest_x == nowx) && (dest_y != nowy)) || ((dest_x != nowx) && (dest_y == nowy))) //�ت��a������ξ�C�~�ಾ��
	{
		if ((dest_x == nowx) && (dest_y != nowy)) //���沾��
		{
			if (dest_y < nowy) //�V�W��
			{
				
			}
			else if(dest_y > nowy) //�V�U��
			{

			}
		}
		else if((dest_x != nowx) && (dest_y == nowy)) //��C����
		{
			if (dest_x < nowx) //�V����
			{

			}
			else if(dest_x > nowx) //�V�k��
			{

			}
		}
		else //�ҥ~���p ���Ӥ��|Ĳ�o �H���U�@�g�@�U
		{
			//���s��J�ت��a
		}
	}
	else
	{
		//���s��J�ت��a
	}
}
