#include <fstream>
#include <conio.h>
#include "ChessBoard.h"

ChessBoard::ChessBoard(vector<vector<int>> chessBoard,bool nowturn)
{
	curX = 0;
	curY = 0;
	curBoard.resize(9);
	for (int i = 0; i < 10; i++)
	{
		curBoard[i].resize(10);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			curBoard[i][j] = chessBoard[i][j];
		}
	}
	turn = nowturn;
}

int ChessBoard::getChess(void)
{
	return curBoard[curX][curY];
}

bool ChessBoard::getTurn(void)
{
	return turn;
}

void ChessBoard::changeTurn(void)
{
	turn = 1 - turn;
}

int ChessBoard::getCurX(void)
{
	return curX;
}

int ChessBoard::getCurY(void)
{
	return curY;
}

void ChessBoard::changeCoordinate(void)
{
	int change = getch();
	switch (change)
	{
	case 72:
		if (curY > 0)
			curY--;
		break;
	case 80:
		if (curY < 9)
			curY++;
		break;
	case 75:
		if (curX > 0)
			curX--;
		break;
	case 77:
		if (curX < 8)
			curX++;
		break;
	}
}

bool ChessBoard::chooseChess(chessBasic**)
{
	int chessType = this->getChess(),nowTurn=this->getTurn();
	int curX = this->getCurX(), curY = this->getCurX();
	if (nowTurn)
	{
		if (chessType < 8)
			return 0;
		switch (chessType)
		{
			//紅方
		}
	}
	else
	{
		if (chessType > 7)
			return 0;
		switch (chessType)
		{
			//黑方
		}
	}
	return 1;
}

void ChessBoard::menu(void)
{
	//遊戲中按ESC
}

int ChessBoard::move(chessBasic* curchess, int destinationX, int destinationY)
{

}

void ChessBoard::saveBoard(void)
{

}

void ChessBoard::regret(void)
{

}

void ChessBoard::saveFile(void)
{

}





