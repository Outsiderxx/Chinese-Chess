#include "slave.h"

bool slave::isMovable(int dest_x, int dest_y, vector< vector<int> > board)
{
	bool passRiverOrNot = false;
	int nowx = getx();
	int nowy = gety();
	int difx = dest_x > nowx ? (dest_x - nowx) : (nowx - dest_x);
	int dify = dest_y > nowy ? (dest_y - nowy) : (nowy - dest_y);
	if (difx + dify >= 2) return 0;
	if (dest_x == nowx && dest_y == nowy) //move to the original position.
	{
		//move again.
		return 0;
	}
	if (!getCamp())  // black
	{
		if (board[dest_y][dest_x] >= 1 && board[dest_y][dest_x] <= 7) { return 0; } // the same camp
		if (nowy >= 5) passRiverOrNot = true;
		if (dest_y < nowy) //slave cannot go back.
		{
			//move again.
			return 0;
		}
		if (!passRiverOrNot) //slave cannot go left or right before pass the river.
		{
			if (dest_x != nowx)
			{
				//move again.
				return 0;
			}
		}
		return 1;
	}
	else		// red
	{
		if (nowy <= 4) passRiverOrNot = true;
		if (board[dest_y][dest_x] >= 8 && board[dest_y][dest_x] <= 14) { return 0; } // the same camp
		if (dest_y > nowy) //slave cannot go back.
		{
			//move again.
			return 0;
		}
		if (!passRiverOrNot) //slave cannot go left or right before pass the river.
		{
			if (dest_x != nowx)
			{
				//move again.
				return 0;
			}
		}
		return 1;
	}
}

vector<vector<bool>> slave::hint(int nowx, int nowy, vector<vector<int>> board)
{
	// initial the hint board
	vector<bool> zeroRows;
	vector<vector<bool>> hint_board;
	bool tempBool = false;
	for (int i = 0; i < 9; ++i)
	{
		zeroRows.push_back(tempBool);
	}
	for (int i = 0; i < 10; ++i)
	{
		hint_board.push_back(zeroRows);
	}
	//--------------------------------------
	bool passRiverOrNot = false;
	if (!getCamp())		//black
	{
		if (nowy >= 5) passRiverOrNot = true;
		if (nowy < 9)
		{
			if (!(board[nowy + 1][nowx] >= 1 && board[nowy + 1][nowx] <= 7))
			{
				hint_board[nowy + 1][nowx] = true;
			}
		}
		if (passRiverOrNot)
		{
			if (nowx == 0)
			{
				if (!(board[nowy][nowx + 1] >= 1 && board[nowy][nowx + 1] <= 7))
				{
					hint_board[nowy][nowx + 1] = true;
				}
			}
			else if (nowx == 8)
			{
				if (!(board[nowy][nowx - 1] >= 1 && board[nowy][nowx - 1] <= 7))
				{
					hint_board[nowy][nowx + 1] = true;
				}
			}
			else if (nowx > 0 && nowx < 8)
			{
				if (!(board[nowy][nowx + 1] >= 1 && board[nowy][nowx + 1] <= 7))
				{
					hint_board[nowy][nowx + 1] = true;
				}
				if (!(board[nowy][nowx - 1] >= 1 && board[nowy][nowx - 1] <= 7))
				{
					hint_board[nowy][nowx - 1] = true;
				}
			}
		}
	}
	else				//red
	{
		if (nowy <= 4) passRiverOrNot = true;
		if (nowy > 0)
		{
			if (!(board[nowy - 1][nowx] >= 8 && board[nowy - 1][nowx] <= 14))
			{
				hint_board[nowy - 1][nowx] = true;
			}
		}
		if (passRiverOrNot)
		{
			if (nowx == 0)
			{
				if (!(board[nowy][nowx + 1] >= 8 && board[nowy][nowx + 1] <= 14))
				{
					hint_board[nowy][nowx + 1] = true;
				}
			}
			else if (nowx == 8)
			{
				if (!(board[nowy][nowx - 1] >= 8 && board[nowy][nowx - 1] <= 14))
				{
					hint_board[nowy][nowx - 1] = true;
				}
			}
			else if (nowx > 0 && nowx < 8)
			{
				if (!(board[nowy][nowx + 1] >= 8 && board[nowy][nowx + 1] <= 14))
				{
					hint_board[nowy][nowx + 1] = true;
				}
				if (!(board[nowy][nowx - 1] >= 8 && board[nowy][nowx - 1] <= 14))
				{
					hint_board[nowy][nowx - 1] = true;
				}
			}
		}
	}
	return hint_board;
}