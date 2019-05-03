#include <fstream>
#include <conio.h>
#include "ChessBoard.h"

//��l�ƴѧ��M�U�Ѥ�
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

//���o��e�y�дѤl����
int ChessBoard::getChess(void)
{
	return curBoard[curY][curX];
}

//���o�U�Ѥ�
bool ChessBoard::getTurn(void)
{
	return turn;
}

//���ܤU�Ѥ�
void ChessBoard::changeTurn(void)
{
	turn = 1 - turn;
}

//���o��e���X�y��
int ChessBoard::getCurX(void)
{
	return curX;
}

//���o��e���Y�y��
int ChessBoard::getCurY(void)
{
	return curY;
}

//���ʴ�Ц�m
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

//��ܵ��
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

//���ʴѤl
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

//�x�s�ѧ�
void ChessBoard::saveBoard(void)
{
	preBoard.push_back(curBoard);
}

//����
void ChessBoard::regret(void)
{
	curBoard = preBoard[preBoard.size() - 2];
}

//�s��
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