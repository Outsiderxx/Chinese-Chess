#include <fstream>
#include <conio.h>
#include "ChessBoard.h"

//初始化棋局和下棋方
ChessBoard::ChessBoard(vector<vector<int>> chessBoard,bool nowturn)
{
	curX = 0;
	curY = 0;
	curBoard.resize(10);
	for (int i = 0; i < 10; i++)
	{
		curBoard[i].resize(9);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			curBoard[i][j] = chessBoard[i][j];
		}
	}
	turn = nowturn;
}

//取得當前座標棋子種類
int ChessBoard::getChess(void)
{
	return curBoard[curY][curX];
}

//取得下棋方
bool ChessBoard::getTurn(void)
{
	return turn;
}

//改變下棋方
void ChessBoard::changeTurn(void)
{
	turn = 1 - turn;
}

//取得當前游標X座標
int ChessBoard::getCurX(void)
{
	return curX;
}

//取得當前游標Y座標
int ChessBoard::getCurY(void)
{
	return curY;
}

//移動游標位置
void ChessBoard::changeCoordinate(void)
{
	int direction = getch();
	switch (direction)
	{
	//UP
	case 72:
		if (curY > 0)
			curY--;
		break;
	//DOWN
	case 80:
		if (curY < 9)
			curY++;
		break;
	//LEFT
	case 75:
		if (curX > 0)
			curX--;
		break;
	//RIGHT
	case 77:
		if (curX < 8)
			curX++;
		break;
	default:
		break;
	}
}

//顯示菜單
int ChessBoard::menu(void)
{    
	int toDo = 0;
	while (true)
	{
		if (kbhit())
		{
			int input = getch();
			if (input == 224)
			{
				input = getch();
				if (input == 72)
				{
					if (input == 0)
						toDo = 2;
					else
						toDo--;
				}
				else if (input == 80)
				{
					if (toDo == 2)
						toDo = 1;
					else
						toDo++;
				}
			}
			if (input == 13)
			{
				if (toDo == 0)
					saveFile();
				else if (toDo == 1)
					return 2;
				else
					return 1;
			}
			if (input == 27)
				return 0;
		}
	}
}

//移動棋子
int ChessBoard::move(chessBasic* curChess)
{
	int returnValue;
	if (getChess() == 1)
		returnValue = 1;
	if (getChess() == 8)
		returnValue = 2;
	else
		returnValue = 0;
	curBoard[curX][curY] = curBoard[curChess->gety()][curChess->getx()];
	curBoard[curChess->gety()][curChess->getx()] = 0;
	curChess->setx(curX);
	curChess->sety(curY);
	return returnValue;
}

//儲存棋局
void ChessBoard::saveBoard(void)
{
	preBoard.push_back(curBoard);
}

//悔棋
void ChessBoard::regret(void)
{
	curBoard = preBoard[preBoard.size() - 2];
}

//存檔
void ChessBoard::saveFile(void)
{
	ofstream output("oldBoard.txt",ios::app);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			output << curBoard[i][j] << " ";
		}
		output << endl;
	}
	output << turn << endl;
}

vector<vector<int>> ChessBoard::getBoard(void)
{
	return curBoard;
}