#include"Elephant.h"

bool Elephant::isMovable(int dest_x, int dest_y, vector<vector<int> > board)
{
	int nowx = getx();
	int nowy = gety();
	if (dest_x == nowx && dest_y == nowy)
	{
		//move again
	}
	if ((dest_x != nowx + 2 && dest_x != nowx - 2) || (dest_y != nowy + 2 && dest_y != nowy - 2))	//illegal moving
	{
		//move again
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
		if (moveCount == 2 && !getCamp())			//no cross river
		{
			return 0;
		}
		if (board[nowy + 1][nowx + 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//black
			{
				moveCount++;
			}
			else									//red
			{
				moveCount--;
			}
			return 1;
		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy + 2)	//move left down
	{
		if (moveCount == 2 && !getCamp())			//no cross river
		{
			return 0;
		}
		if (board[nowy - 1][nowx + 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//black
			{
				moveCount++;
			}
			else									//red
			{
				moveCount--;
			}
			return 1;
		}
	}
	if (dest_x == nowx + 2 && dest_y == nowy - 2)	//move right up
	{
		if (moveCount == 2 && getCamp())			//no cross river
		{
			return 0;
		}
		if (board[nowy + 1][nowx - 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		else
		{
			if (!getCamp())							//black
			{
				moveCount--;
			}
			else									//red
			{
				moveCount++;
			}
			return 1;
		}
	}
	if (dest_x == nowx - 2 && dest_y == nowy - 2)	//move left up
	{
		if (moveCount == 2 && getCamp())			//no cross river
		{
			return 0;
		}
		if (board[nowy - 1][nowx - 1] != 0)			//be blocked by other chess(elephant eye)
		{
			return 0;
		}
		else
		{
			if (!getCamp)							//black
			{
				moveCount--;
			}
			else									//red
			{
				moveCount++;
			}
			return 1;
		}
	}
}