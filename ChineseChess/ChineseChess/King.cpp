#include"King.h"

bool King::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
		return 0;
	}
	if ((dest_x != nowx && dest_y != nowy) || (dest_x == nowx && (dest_y > nowy + 1 || dest_y < nowy - 1)) || (dest_y == nowy && (dest_x > nowx + 1 || dest_x < nowx - 1)))			//illegal moving
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
	if (dest_x == nowx && dest_y == nowy + 1)		//move down side
	{
		if (!getCamp())		//black					//confined to the nine point fortress
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
	if (dest_x == nowx && dest_y == nowy - 1)		//move up side
	{
		if (!getCamp())		//black					//confined to the nine point fortress
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
	if (dest_x == nowx + 1 && dest_y == nowy)		//move right side
	{
		if (dest_x > 5 || dest_x < 3)				//confined to the nine point fortress
		{
			return 0;
		}
		return 1;
	}
	if (dest_x == nowx - 1 && dest_y == nowy)		//move left side
	{
		if (dest_x > 5 || dest_x < 3)				//confined to the nine point fortress
		{
			return 0;
		}
		return 1;
	}
	return 0;
}

bool King::kingMeetKing(King& enemyKing, vector<vector<int> > board)	//king meet king
{
	if (getx() == enemyKing.getx())
	{
		for (int loop = gety() > enemyKing.gety() ? enemyKing.gety() + 1 : gety() + 1; loop < gety() > enemyKing.gety() ? gety() : enemyKing.gety(); loop++)
		{
			if (board[loop][getx()] != 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
vector<vector<bool> > King::hint(int nowx, int nowy, vector<vector<int> > board)
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
	if (nowx + 1 <= 5)							//right side
	{
		if (board[nowy][nowx + 1] != 0 && !getCamp() && board[nowy][nowx + 1] <= 7)
		{
			//can't move
		}
		else if (board[nowy][nowx + 1] != 0 && getCamp() && board[nowy][nowx + 1] > 7)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy][nowx + 1] = 1;	//move hint
		}
	}
	if (nowx - 1 >= 3)							//left side
	{
		if (board[nowy][nowx - 1] != 0 && !getCamp() && board[nowy][nowx - 1] <= 7)
		{
			//can't move
		}
		else if (board[nowy][nowx - 1] != 0 && getCamp() && board[nowy][nowx - 1] > 7)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy][nowx - 1] = 1;	//move hint
		}
	}
	if (nowy + 1 < 10)							//down side
	{
		if (!getCamp() && nowy + 1 > 2)			//black					//confined to the nine point fortress
		{
			//can't move
		}
		else if (board[nowy + 1][nowx] != 0 && !getCamp() && board[nowy + 1][nowx] <= 7)
		{
			//can't move
		}
		else if (board[nowy + 1][nowx] != 0 && getCamp() && board[nowy + 1][nowx] > 7)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy + 1][nowx] = 1;
		}
	}
	if (nowy - 1 >= 0)							//up side
	{
		if (getCamp() && nowy - 1 < 7)			//red					//confined to the nine point fortress
		{
			//can't move
		}
		else if (board[nowy - 1][nowx] != 0 && !getCamp() && board[nowy - 1][nowx] <= 7)
		{
			//can't move
		}
		else if (board[nowy - 1][nowx] != 0 && getCamp() && board[nowy - 1][nowx] > 7)
		{
			//can't move
		}
		else
		{
			anotherBoard[nowy - 1][nowx] = 1;
		}
	}
	return anotherBoard;

}