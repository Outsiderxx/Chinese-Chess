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
//toDo=0 �~�� toDo=1 �s�� toDo=2 �뭰 toDo=3 ���� toDo=4 ���� toDo=5 ���}�C�� 
int ChessBoard::menu(void)
{    
	int toDo = 0;
	//ESC�M��e��
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
						toDo = 0;
					else
						toDo--;
				}
				else if (input == 80)
				{
					if (toDo == 5)
						toDo = 5;
					else
						toDo++;
				}
			}
			else if(input == 13)
			{
				switch (toDo)
				{
				case 0:
					return 0;
				case 1:
					saveFile();
					break;
				case 2:
					return 1;
				case 3:
					return 2;
				case 4:
					regret();
					return 0;
				case 5:
					saveFile();
					return 3;
				}
			}
		}
	}
}

//���ʴѤl
int ChessBoard::move(chessBasic* curChess)
{
	int returnValue;
	if (getChess() == 1)
		returnValue = 1;
	else if(getChess() == 8)
		returnValue = 2;
	else
		returnValue = 0;
	curBoard[curY][curX] = curBoard[curChess->gety()][curChess->getx()];
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
	if (preBoard.size() > 2)
	{
		curBoard = preBoard[preBoard.size() - 2];
		preBoard.pop_back();
		preBoard.pop_back();
	}
	else
	{
		cout << "�L�k����" << endl;
	}
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

void ChessBoard::printBoard(void)
{
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (curBoard[i][j])
			{
			case 1:
				cout << "�N ";
				break;
			case 2:
				cout << "�h ";
				break;
			case 3:
				cout << "�H ";
				break;
			case 4:
				cout << "�� ";
				break;
			case 5:
				cout << "�� ";
				break;
			case 6:
				cout << "�] ";
				break;
			case 7:
				cout << "�� ";
				break;
			case 8:
				cout << "�� ";
				break;
			case 9:
				cout << "�K ";
				break;
			case 10:
				cout << "�� ";
				break;
			case 11:
				cout << "�� ";
				break;
			case 12:
				cout << "�� ";
				break;
			case 13:
				cout << "�� ";
				break;
			case 14:
				cout << "�L ";
				break;
			default:
				cout << "�� ";
				break;
			}
		}
		cout << endl << endl;
	}
	if (turn)
		cout << "����U��" << endl;
	else
		cout << "�¤�U��" << endl;
}

void ChessBoard::replay(void)
{
	curBoard = preBoard[0];
	printBoard();
	int index = 1;
	while (true)
	{
		if (index == preBoard.size())
		{
			system("pause");
			break;
		}
		if (kbhit())
		{
			int input = getch();
			if (input == 13)
			{
				curBoard = preBoard[index];
				printBoard();
				index++;
			}
		}
	}
}

void ChessBoard::win(bool whoWin)
{
	system("cls");
	if (whoWin)
		cout << "�����" << endl;
	else
		cout << "�¤��" << endl;
	bool replayFlag = 1;
	while (true)
	{
		if (kbhit())
		{
			int input = getch();
			if (input == 224)
			{
				input = getch();
				replayFlag = 1 - replayFlag;
			}
			else if (input == 13)
			{
				if (replayFlag)
					replay();
				break;
			}
		}
	}
}

bool ChessBoard::kingMeetKing(vector<vector<int>> board)	//king meet king
{
	int kingX1, kingX2, kingY1,kingY2;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 1)
			{
				kingY1 = i;
				kingX1 = j;
			}
			if (board[i][j] == 8)
			{
				kingY2 = i;
				kingX2 = j;
			}
		}
	}
	if (kingX1 == kingX2)
	{
		for (int loop=kingY1+1;loop<kingY2;loop++)
		{

			if (board[loop][kingX1] != 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}