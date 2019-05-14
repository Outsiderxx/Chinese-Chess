#include"Horse.h"

bool Horse::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if (board[dest_y][dest_x] != 0)						//same camp
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
	if (dest_x == nowx + 2 && dest_y == nowy + 1)		//position 1 in horse.png
	{
		if (board[nowy][nowx + 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 1)		//position 2 in horse.png
	{
		if (board[nowy][nowx + 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 1 && dest_y == nowy - 2)		//position 3 in horse.png
	{
		if (board[nowy - 1][nowx] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy - 2)		//position 4 in horse.png
	{
		if (board[nowy - 1][nowx] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 1)		//position 5 in horse.png
	{
		if (board[nowy][nowx - 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 1)		//position 6 in horse.png
	{
		if (board[nowy][nowx - 1] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy + 2)		//position 7 in horse.png
	{
		if (board[nowy + 1][nowx] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 1 && dest_y == nowy + 2)		//position 8 in horse.png
	{
		if (board[nowy + 1][nowx] != 0)					//be blocked by other chess
		{
			return 0;
		}
		return 1;
	}
	return 0;
}
vector<vector<bool> > Horse::hint(int nowx, int nowy, vector<vector<int> >board)
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
	if (nowx + 2 < 9 && nowy + 1 < 10)					//position 1 in horse.png
	{
		if (board[nowy][nowx + 1] != 0)					//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy + 1][nowx + 2] != 0 && !getCamp() && board[nowy + 1][nowx + 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx + 2] != 0 && getCamp() && board[nowy + 1][nowx + 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 1][nowx + 2] = 1;			//move hint
		}
	}
	if (nowx + 2 < 9 && nowy - 1 >= 0)						//position 2 in horse.png
	{
		if (board[nowy][nowx + 1] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy - 1][nowx + 2] != 0 && !getCamp() && board[nowy - 1][nowx + 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx + 2] != 0 && getCamp() && board[nowy - 1][nowx + 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 1][nowx + 2] = 1;			//move hint
		}
	}
	if (nowx + 1 < 9 && nowy - 2 >= 0)						//position 3 in horse.png
	{
		if (board[nowy - 1][nowx] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy - 2][nowx + 1] != 0 && !getCamp() && board[nowy - 2][nowx + 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 2][nowx + 1] != 0 && getCamp() && board[nowy - 2][nowx + 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 2][nowx + 1] = 1;			//move hint
		}
	}
	if (nowx - 1 >= 0 && nowy - 2 >= 0)						//position 4 in horse.png
	{
		if (board[nowy - 1][nowx] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy - 2][nowx - 1] != 0 && !getCamp() && board[nowy - 2][nowx - 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 2][nowx - 1] != 0 && getCamp() && board[nowy - 2][nowx - 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 2][nowx - 1] = 1;			//move hint
		}
	}
	if (nowx - 2 >= 0 && nowy - 1 >= 0)						//position 5 in horse.png
	{
		if (board[nowy][nowx - 1] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy - 1][nowx - 2] != 0 && !getCamp() && board[nowy - 1][nowx - 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx - 2] != 0 && getCamp() && board[nowy - 1][nowx - 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 1][nowx - 2] = 1;			//move hint
		}
	}
	if (nowx - 2 >= 0 && nowy + 1 < 10)						//position 6 in horse.png
	{
		if (board[nowy][nowx - 1] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy + 1][nowx - 2] != 0 && !getCamp() && board[nowy + 1][nowx - 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx - 2] != 0 && getCamp() && board[nowy + 1][nowx - 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 1][nowx - 2] = 1;			//move hint
		}
	}
	if (nowx - 1 >= 0 && nowy + 2 < 10)						//position 7 in horse.png
	{
		if (board[nowy + 1][nowx] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy + 2][nowx - 1] != 0 && !getCamp() && board[nowy + 2][nowx - 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 2][nowx - 1] != 0 && getCamp() && board[nowy + 2][nowx - 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 2][nowx - 1] = 1;			//move hint
		}
	}
	if (nowx + 1 < 9 && nowy + 2 < 10)						//position 8 in horse.png
	{
		if (board[nowy + 1][nowx] != 0)						//be blocked by other chess
		{
			//can't move
		}
		else if (board[nowy + 2][nowx + 1] != 0 && !getCamp() && board[nowy + 2][nowx + 1] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 2][nowx + 1] != 0 && getCamp() && board[nowy + 2][nowx + 1] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 2][nowx + 1] = 1;			//move hint
		}
	}
	return anotherBoard;
}