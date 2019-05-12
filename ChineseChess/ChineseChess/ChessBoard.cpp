#include <fstream>
#include <conio.h>
#include "ChessBoard.h"
#include "start_menu.h"
#include "menu_operate.h"

//��l�ƴѧ��M�U�Ѥ�
ChessBoard::ChessBoard(vector<vector<int>> chessBoard,bool nowTurn)
{
	curX = 0;
	if (nowTurn == 0)
		curY = 0;
	else
		curY = 9;
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
	turn = nowTurn;
}

//���o��e�y�дѤl����
int ChessBoard::getChess(int coorY,int coorX)
{
	return curBoard[coorY][coorX];
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
	if (getChess(curY, curX) == 1)
		returnValue = 2;
	else if(getChess(curY, curX) == 8)
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
		if (preBoard.size() % 12 == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(6, 3);
			cout << "                   ";
			gotoxy(6, 3 + 2 * 11);
			cout << "                   ";
		}
		else if (preBoard.size() % 12 == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(6, 3 + 2 * 10);
			cout << "                   ";
			gotoxy(6, 3 + 2 * 11);
			cout << "                   ";
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(6, 3 + (preBoard.size() % 12 - 2) * 2);
			cout << "                   ";
			gotoxy(6, 3 + (preBoard.size() % 12 - 2) * 2 - 2);
			cout << "                   ";
		}
		curBoard = preBoard[preBoard.size() - 3];
		printBoard();
		preBoard.pop_back();
		preBoard.pop_back();
	}
	else
	{
		gotoxy(90, 8);
		cout << "�L�k����";
		gotoxy(85, 9);
		system("pause");
		gotoxy(90, 8);
		cout << "            ";
		gotoxy(85, 9);
		cout << "                     ";
		gotoxy(34 + 4 * curX, 2 + 2 * curY);
	}
}

//�s��
void ChessBoard::saveFile(void)
{
	vector<vector<vector<int>>> allBoard;
	vector<vector<int>> tmpBoard;
	vector<bool> allTurn;
	bool tmpTurn;
	ifstream inputFile("oldBoard.txt");
	tmpBoard.resize(10);
	for (int i = 0; i < 10; i++)
	{
		tmpBoard[i].resize(9);
	}
	while (true)
	{
		//�N�ɮפ��eŪ����vector
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				inputFile >> tmpBoard[i][j];
			}
		}
		inputFile >> tmpTurn;
		if (inputFile.eof())
			break;
		allBoard.push_back(tmpBoard);
		allTurn.push_back(tmpTurn);
	}
	inputFile.close();
	tmpBoard = curBoard;
	tmpTurn = turn;
	if (allBoard.size() == 10)
	{
		for (int i = 0; i < 9; i++)
		{
			allBoard[i] = allBoard[i + 1];
			allTurn[i] = allTurn[i + 1];
		}
		allBoard.pop_back();
		allTurn.pop_back();
	}
	allBoard.push_back(tmpBoard);
	allTurn.push_back(tmpTurn);
	ofstream outputFile("oldBoard.txt");
	for (int k = 0; k < allBoard.size(); k++)
	{
		for (int i = 0; i < 10; i++)
		{
			for(int j=0;j<9;j++)
			{
				outputFile << allBoard[k][i][j] << " ";
			}
			outputFile << endl;
		}
		outputFile << allTurn[k] << endl;
	}
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
		gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);	cout << "�¤�� ! ! !" ;
	}
	else
	{
		gotoxy(82, 4); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	cout << "                             ";
		gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	cout << "����� ! ! !" ;
	}
	gotoxy(82, 11);
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(82, 11);
	cout << "                         ";
	gotoxy(87, 10);
	cout << "                        ";
	gotoxy(80, 5);
	cout << " �O�_�n�[�ݭ��� ";
	bool replayFlag = 1;
	gotoxy(94, 7);
	cout << "�_(�^�D�e��)";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(90, 7);
	cout << "�O";
	gotoxy(117, 29);
	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == 224)
			{
				input = _getch();
				if (input == 75)
					replay_left_gotoxy();
				else if (input == 77)
					replay_right_gotoxy();
				replayFlag = 1 - replayFlag;
			}
			else if (input == 13)
			{
				if (replayFlag)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(80, 5);
					cout << "                ";
					gotoxy(90, 7);
					cout << "                   ";
					replay();
				}
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

void ChessBoard::printChess(int chessType)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	const string chessName[15] = { "","�N","�h" ,"�H" ,"��" ,"��" ,"�]" ,"��" ,"��" ,"�K" ,"��" ,"��" ,"�X" ,"��" ,"�L" };
	if (!turn)
	{
		cout << "��e��ܪ��Ѥl�O ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		cout << chessName[chessType];
	}
	else
	{
		cout << "��e��ܪ��Ѥl�O ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		cout << chessName[chessType + 7];
	}
}

void ChessBoard::printStatus(int chessX, int chessY)
{
	int moveY = curY - chessY, chessType = getChess(chessY, chessX);
	const string number[10] = { "�@","�G","�T","�|","��","��","�C","�K","�E" };
	const string chessName[15] = { "","�N","�h" ,"�H" ,"��" ,"��" ,"�]" ,"��" ,"��" ,"�K" ,"��" ,"��" ,"�X" ,"��" ,"�L" };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	if (preBoard.size() % 12 == 0)
		gotoxy(6, 3 + 2 * 11);
	else
		gotoxy(6, 3 + 2 * (preBoard.size() % 12 - 1));
	cout << preBoard.size() << " ";
	if (turn)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		cout << "��";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << " : " << chessName[chessType] << " " << number[8 - chessX];
		if (moveY < 0)
			cout << " �i ";
		else if (moveY == 0)
			cout << " �� ";
		else
			cout << " �h ";
		if (chessType == 8 || chessType == 11 || chessType == 13 || chessType == 14)
		{
			if (moveY == 0)
				cout << number[8 - curX];
			else
			{
				if (moveY < 0)
					moveY *= -1;
				cout << number[moveY - 1];
			}
		}
		else
			cout << number[8 - curX];
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		cout << "��";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << " : " << chessName[chessType] << "  " << chessX + 1;
		if (moveY > 0)
			cout << " �i  ";
		else if (moveY == 0)
			cout << " ��  ";
		else
			cout << " �h  ";
		if (chessType == 1 || chessType == 4 || chessType == 6 || chessType == 7)
		{
			if (moveY == 0)
				cout << curX + 1;
			else
			{
				if (moveY < 0)
					moveY *= -1;
				cout << moveY;
			}
		}
		else
			cout << curX + 1;
	}
}