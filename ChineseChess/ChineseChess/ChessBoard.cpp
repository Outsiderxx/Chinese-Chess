#include <fstream>
#include "ChessBoard.h"

ChessBoard::ChessBoard(string chessBoard)
{
	curX = 0;
	curY = 0;
	curBoard.resize(9);
	for (int i = 0; i < 10; i++)
	{
		curBoard[i].resize(10);
	}
	ifstream inputBoard(chessBoard);
	if (inputBoard.is_open())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				inputBoard >> curBoard[i][j];
			}
		}
		inputBoard >> turn;
	}
}

int ChessBoard::getChess(void)
{
	return curBoard[curX][curY];
}