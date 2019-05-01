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
	int board[9][10] = { 0 }; //假設的棋盤 之後用main裡的
	if (dest_x == nowx && dest_y == nowy) //移動到原位 重新移動
	{
		//重新輸入目的地
	}
	if (((dest_x == nowx) && (dest_y != nowy)) || ((dest_x != nowx) && (dest_y == nowy))) //目的地為直行或橫列才能移動
	{
		if ((dest_x == nowx) && (dest_y != nowy)) //直行移動
		{
			if (dest_y < nowy) //向上走
			{
				
			}
			else if(dest_y > nowy) //向下走
			{

			}
		}
		else if((dest_x != nowx) && (dest_y == nowy)) //橫列移動
		{
			if (dest_x < nowx) //向左走
			{

			}
			else if(dest_x > nowx) //向右走
			{

			}
		}
		else //例外狀況 應該不會觸發 以防萬一寫一下
		{
			//重新輸入目的地
		}
	}
	else
	{
		//重新輸入目的地
	}
}
