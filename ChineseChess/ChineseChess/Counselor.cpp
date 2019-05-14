#include"Counselor.h"

bool Counselor::isMovable(int dest_x, int dest_y, vector<vector<int >> board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if ((dest_x != nowx + 1 && dest_x != nowx - 1) || (dest_y != nowy + 1 && dest_y != nowy - 1))	//illegal moving
	{
		//move again
		return 0;
	}
	if (board[dest_y][dest_x] != 0)				//same camp
	{
		if (board[dest_y][dest_x] <= 7 && !getCamp())
		{
			return 0;
		}
		if (board[dest_y][dest_x] > 7 && getCamp())
		{
			return 0;
		}
	}
	if (dest_x == nowx + 1 && dest_y == nowy + 1)		//move right down
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
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
	if (dest_x == nowx - 1 && dest_y == nowy + 1)		//move left down
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
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
	if (dest_x == nowx + 1 && dest_y == nowy - 1)		//move right up
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
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
	if (dest_x == nowx - 1 && dest_y == nowy - 1)		//move left down
	{
		if (dest_x > 5 || dest_x < 3)					//confined to the nine point fortress
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
	return 0;
}
vector<vector<bool> > Counselor::hint(int nowx, int nowy, vector<vector<int> >board)
{
	vector<vector<bool> >anotherBoard;
	anotherBoard.resize(10);
	for (int loop = 0; loop < 10; loop++)
	{
		anotherBoard[loop].resize(9);
	}
	for (int loop = 0; loop < 10; loop++)
	{
		for (int loop1 = 0; loop1 < 9; loop1++)
		{
			anotherBoard[loop][loop1] = 0;
		}
	}

	if (nowx + 1 < 9 && nowy + 1 < 10)						//right down
	{
		if (!getCamp() && nowy + 1 > 2)						//confined to the nine point fortress
		{
			//can't move
		}
		else if (nowx + 1 > 5)								//confined to the nine point fortress
		{
			//can't move
		}
		else if (board[nowy + 1][nowx + 1] != 0 && !getCamp() && board[nowy + 1][nowx + 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx + 1] != 0 && getCamp() && board[nowy + 1][nowx + 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 1][nowx + 1] = 1;			//move hint
		}
	}
	if (nowx - 1 >= 0 && nowy + 1 < 10)						//left down
	{
		if (!getCamp() && nowy + 1 > 2)						//confined to the nine point fortress
		{
			//can't move
		}
		else if (nowx - 1 < 3)								//confined to the nine point fortress
		{
			//can't move
		}
		else if (board[nowy + 1][nowx - 1] != 0 && !getCamp() && board[nowy + 1][nowx - 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx - 1] != 0 && getCamp() && board[nowy + 1][nowx - 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 1][nowx - 1] = 1;			//move hint
		}
	}
	if (nowx + 1 < 9 && nowy - 1 >= 0)						//right up
	{
		if (getCamp() && nowy - 1 < 7)						//confined to the nine point fortress
		{
			//can't move
		}
		else if (nowx + 1 > 5)								//confined to the nine point fortress
		{
			//can't move
		}
		else if (board[nowy - 1][nowx + 1] != 0 && !getCamp() && board[nowy - 1][nowx + 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx + 1] != 0 && getCamp() && board[nowy - 1][nowx + 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 1][nowx + 1] = 1;			//move hint
		}
	}
	if (nowx - 1 >= 0 && nowy - 1 >= 0)						//left up
	{
		if (getCamp() && nowy - 1 < 7)						//confined to the nine point fortress
		{
			//can't move
		}
		else if (nowx - 1 < 3)								//confined to the nine point fortress
		{
			//can't move
		}
		else if (board[nowy - 1][nowx - 1] != 0 && !getCamp() && board[nowy - 1][nowx - 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx - 1] != 0 && getCamp() && board[nowy - 1][nowx - 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 1][nowx - 1] = 1;			//move hint
		}
	}
	return anotherBoard;
}