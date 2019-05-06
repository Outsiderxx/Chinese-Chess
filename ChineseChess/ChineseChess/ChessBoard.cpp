#include <fstream>
#include <conio.h>
#include "ChessBoard.h"
#include "start_menu.h"
#include "menu_operate.h"

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
	int direction = _getch();
	switch (direction)
	{
	//UP
	case 72:
		if (curY > 0) { curY--;	gotoxy(34 + curX * 4, 2 + curY * 2); }	
		break;
	//DOWN
	case 80:
		if (curY < 9) { curY++;	gotoxy(34 + curX * 4, 2 + curY * 2); }
		break;
	//LEFT
	case 75:
		if (curX > 0) { curX--;	gotoxy(34 + curX * 4, 2 + curY * 2); }	
		break;
	//RIGHT
	case 77:
		if (curX < 8) { curX++; gotoxy(34 + curX * 4, 2 + curY * 2); }	
		break;
	default:	
		break;
	}
}

//��ܵ��
//toDo=0 �~�� toDo=1 �s�� toDo=2 �뭰 toDo=3 ���� toDo=4 ���� toDo=5 ���}�C�� ---------------------------------------������
int ChessBoard::menu(void)
{
	int toDo = 0;
	escmenu();					//ESC�M��e��
	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == 224)
			{
				input = _getch();
				if (input == 75)			//��
				{
					if (toDo == 0)
						toDo = 0;
					else
					{
						toDo--;
						esc_left_gotoxy(toDo);
					}
				}
				else if (input == 77)		//�k
				{
					if (toDo == 5)
						toDo = 5;
					else
					{
						toDo++;
						esc_right_gotoxy(toDo);
					}
				}
			}
			else if (input == 13)		//enter�T�w���
			{
				switch (toDo)			//�����ʧ@�M�����e����в���W�@�B��m
				{
				case 0: {	escclear();	gotoxy(34 + curX * 4, 2 + curY * 2); return 0; }
				case 1: {	saveFile();	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2);  return 0; }
				case 2: {	escclear();	gotoxy(34 + curX * 4, 2 + curY * 2); return 1; }
				case 3: {	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2); return 2; }
				case 4: {	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2); regret(); return 0; }		
				case 5: {	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2); return 3; }
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
		returnValue = 2;
	else if(getChess() == 8)
		returnValue = 1;
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
		curBoard = preBoard[preBoard.size() - 3];
		printBoard();
		preBoard.pop_back();
		preBoard.pop_back();
	}
	else
	{
		gotoxy(90, 8);
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
	int x = 30, y = 0;
	board_basic(34, 2);
	for (int i = 0; i < 10; i++)
	{
		y = y + 2;	
		gotoxy(x, y);
		for (int j = 0; j < 9; j++)
		{
			x = x + 4;		
			gotoxy(x, y);
			switch (curBoard[i][j])
			{
			case 1: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "�N";	break; }
			case 2: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "�h";	break; }
			case 3: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "�H";	break; }
			case 4: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "��";	break; }
			case 5: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "��";	break; }
			case 6: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "�]";	break; }
			case 7: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "��";	break; }
			case 8: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "��";	break; }
			case 9: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "�K";	break; }
			case 10: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "��";	break; }
			case 11: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "��";	break; }
			case 12: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "�X";	break; }
			case 13: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "��";	break; }
			case 14: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "�L";	break; }
			}
		}
		x = 30;
	}
	if (turn)
	{
		gotoxy(92, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	cout << "����U��";
	}
	else
	{
		gotoxy(92, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);	 cout << "�¤�U��";
	}
	gotoxy(34 + curX * 4, 2 + curY * 2);
}

void ChessBoard::replay(void)
{
	curBoard = preBoard[0];
	printBoard();
	gotoxy(82, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
	gotoxy(85, 8);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~~~~������~~~~~~";
	gotoxy(85, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~��enter���U�@��~~~";
	int index = 1;
	while (true)
	{
		if (index == preBoard.size())
		{
			gotoxy(85, 8);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
			gotoxy(85, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
			gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "��������~~";
			gotoxy(87, 11); system("pause");
			break;
		}
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13)
			{
				curBoard = preBoard[index];
				printBoard();
				index++;
				gotoxy(82, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
				gotoxy(85, 8);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~~~~������~~~~~~";
				gotoxy(85, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~��enter���U�@��~~~";
			}
		}
	}
}

void ChessBoard::win(bool whoWin)
{
	if (!whoWin)
	{
		gotoxy(82, 4); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	cout << "                             ";
		gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);	cout << "�¤�� ! ! ! ! !";
	}
	else
	{
		gotoxy(82, 4); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	cout << "                             ";
		gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	cout << "����� ! ! ! ! !";
	}
	bool replayFlag = 1;
	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == 224)
			{
				input = _getch();
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