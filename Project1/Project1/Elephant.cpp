#include"Elephant.h"

bool Elephant::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if ((dest_x != nowx + 2 && dest_x != nowx - 2) || (dest_y != nowy + 2 && dest_y != nowy - 2))	//illegal moving
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
	if (dest_x == nowx + 2 && dest_y == nowy + 2)	//move right down
	{
		if (!getCamp() && dest_y > 4)				//no cross river(black)
		{
			return 0;
		}
		if (getCamp() && dest_y < 5)				//no cross river(red)
		{
			return 0;
		}
		if (board[nowy + 1][nowx + 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 2)	//move left down
	{
		if (!getCamp() && dest_y > 4)				//no cross river(black)
		{
			return 0;
		}
		if (getCamp() && dest_y < 5)				//no cross river(red)
		{
			return 0;
		}
		if (board[nowy + 1][nowx - 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 2)	//move right up
	{
		if (!getCamp() && dest_y > 4)				//no cross river(black)
		{
			return 0;
		}
		if (getCamp() && dest_y < 5)				//no cross river(red)
		{
			return 0;
		}
		if (board[nowy - 1][nowx + 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 2)	//move left up
	{
		if (!getCamp() && dest_y > 4)				//no cross river(black)
		{
			return 0;
		}
		if (getCamp() && dest_y < 5)				//no cross river(red)
		{
			return 0;
		}
		if (board[nowy - 1][nowx - 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		return 1;
	}
	return 0;
}

vector<vector<bool> > Elephant::hint(int nowx, int nowy, vector<vector<int> > board)
{
	vector<vector<bool> >anotherBoard;
	anotherBoard.resize(9);
	for (int loop = 0; loop < 9; loop++)
	{
		anotherBoard[loop].resize(10);
	}
	for (int loop = 0; loop < 9; loop++)
	{
		for (int loop1 = 0; loop1 < 10; loop1++)
		{
			anotherBoard[loop][loop1] = 0;
		}
	}

	if (nowx + 2 < 9 && nowy + 2 < 10)						//right down
	{
		if (!getCamp() && nowy + 2 > 4)						//no cross river(black)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx + 1] != 0)			//be blocked
		{
			//can't move
		}
		else if (board[nowy + 2][nowx + 2] != 0 && !getCamp() && board[nowy + 2][nowx + 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 2][nowx + 2] != 0 && getCamp() && board[nowy + 2][nowx + 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 2][nowx + 2] = 1;			//move hint
		}
	}
	if (nowx - 2 >= 0 && nowy + 2 < 10)						//left down
	{
		if (!getCamp() && nowy + 2 > 4)						//no cross river(black)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx - 1] != 0)			//be blocked
		{
			//can't move
		}
		else if (board[nowy + 2][nowx - 2] != 0 && !getCamp() && board[nowy + 2][nowx - 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 2][nowx - 2] != 0 && getCamp() && board[nowy + 2][nowx - 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 2][nowx - 2] = 1;			//move hint
		}
	}
	if (nowx + 2 < 9 && nowy - 2 >= 0)						//right up
	{
		if (getCamp() && nowy - 2 < 5)						//no cross river(red)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx + 1] != 0)			//be blocked
		{
			//can't move
		}
		else if (board[nowy - 2][nowx + 2] != 0 && !getCamp() && board[nowy - 2][nowx + 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy - 2][nowx + 2] != 0 && getCamp() && board[nowy - 2][nowx + 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 2][nowx + 2] = 1;			//move hint
		}
	}
	if (nowx - 2 >= 0 && nowy - 2 >= 0)						//left up
	{
		if (getCamp() && nowy - 2 < 5)						//no cross river(red)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx - 1] != 0)			//be blocked
		{
			//can't move
		}
		else if (board[nowy + 2][nowx + 2] != 0 && !getCamp() && board[nowy + 2][nowx + 2] <= 7)	//same camp(black)
		{
			//can't move
		}
		else if (board[nowy + 2][nowx + 2] != 0 && getCamp() && board[nowy + 2][nowx + 2] > 7)		//same camp(red)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 2][nowx - 2] = 1;			//move hint
		}
	}
	return anotherBoard;
}