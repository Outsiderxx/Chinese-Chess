#include <iostream>
#include <fstream>
#include <conio.h>
#include "ChineseChess.h"
#include "ChessBoard.h"
#include "ChessBasic.h"
#include "King.h"
#include "Elephant.h"
#include "Counselor.h"
#include "Car.h"
#include "Bubble.h"
#include "slave.h"
#include "Horse.h"
#include "start_menu.h"
#include "menu_operate.h"
using namespace std;

//intent:�i��C��
//pre:�ǤJ�ѧ�
//post:�^�Ǵѧ����G
void ChineseChess::playGame()
{
	//��l�ƴѧ�
	ChessBoard board(initialPlayBoard,initialTurn);
	initial_start();
	//�O�_�w���
	bool haveChose = 0;
	gotoxy(34, 20);
	//�x�s�ѽL
	board.saveBoard();
	//��X�ѽL
	board.printBoard();
	//�Ѥl
	chessBasic *chess = NULL;
	while (true)
	{
		//������L�O�_����J
		if (_kbhit())
		{
			int input = getch();
			//��J��V��
			if (input == 224)
			{
				//�̷Ӥ�V����ܮy��
				board.changeCoordinate();
			}
			//��JENTER
			else if (input == 13)
			{
				//�Y����ܴѤl�A�i����
				if (!haveChose)
				{
					King kingChess;
					Counselor counselorChess;
					Elephant elephantChess;
					Car carChess;
					Horse horseChess;
					bubble bubbleChess;
					slave slaveChess;
					//�P�_������X�l�O�_���v��
					if (((board.getTurn() && board.getChess(board.getCurY(),board.getCurX()) > 7) || (!board.getTurn() && board.getChess(board.getCurY(), board.getCurX()) < 8)) && board.getChess(board.getCurY(), board.getCurX()) != 0)
					{
						//�w��ܴѤl
						haveChose = 1;
						gotoxy(85, 8);
						int chessType = board.getChess(board.getCurY(), board.getCurX()) - board.getTurn() * 7;
						board.printChess(chessType);
						//�ھڴѽL�W���Ʀr�A��ܹ������Ѥl
						switch (chessType)
						{
						case 1:
							chess = &kingChess;
							break;
						case 2:
							chess = &counselorChess;
							break;
						case 3:
							chess = &elephantChess;
							break;
						case 4:
							chess = &carChess;
							break;
						case 5:
							chess = &horseChess;
							break;
						case 6:
							chess = &bubbleChess;
							break;
						case 7:
							chess = &slaveChess;
							break;
						default:
							break;
						}
						//�]�w�Ѥl�y�а}��
						chess->setx(board.getCurX());
						chess->sety(board.getCurY());
						chess->setCamp(board.getTurn());
						gotoxy(34 + 4 * board.getCurX(), 2 + 2 * board.getCurY());
					}
				}
				//�w��ܴѤl�A�i�沾��
				else
				{
					//�i���ʨ�ؼЮy��
					if (chess->isMovable(board.getCurX(), board.getCurY(), board.getBoard()))
					{
						int haveWin = 0;
						//�Ԫp���
						board.printStatus(chess->getx(),chess->gety());
						//�i�沾��
						haveWin = board.move(chess);
						//�O�_����������p�X�{
						if (board.kingMeetKing(board.getBoard()))
						{
							//������X�{�ɡA���ӧQ
							if (board.getTurn())
								haveWin = 1;
							else
								haveWin = 2;
						}
						//���ܿ�Ѫ��A
						haveChose = 0;
						//�x�s�ѧ�
						board.saveBoard();
						//���t�@��ʧ@
						board.changeTurn();
						//��X�ѧ�
						board.printBoard();
						gotoxy(85, 8);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << "                     ";
						gotoxy(34 + 4 * board.getCurX(), 2 + 2 * board.getCurY());
						//�P�_�ӭt���A
						if (haveWin == 1)
						{
							board.win(0);
							break;
						}
						else if (haveWin == 2)
						{
							board.win(1);
							break;
						}
					}
				}
			}
			//�s�X���
			else if (input == 27)
			{
				int leaveFlag;
				leaveFlag = board.menu();
				//��ܧ뭰�A���ӧQ
				if (leaveFlag == 1)
				{
					if (board.getTurn())
					{
						board.win(0);
						break;
					}
					else
					{
						board.win(1);
						break;
					}
				}
				//��ܻ�����
				else if (leaveFlag == 2)
				{
					system("cls");
					getManual();
					initial_start();
					board.printBoard();
				}
				//���}�C��
				else if (leaveFlag == 3)
					exitGame();
			}
			//������ܴѤl
			else if (input == 'q')
			{
				haveChose = 0;
				gotoxy(85, 8);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "                     ";
				gotoxy(34 + 4 * board.getCurX(), 2 + 2 * board.getCurY());
			}
		}
	}
}

//intent:�]�w���檺�ʧ@
//pre:����w�إ�
//post:�x�s�ϥΪ̿�ܪ��Ҧ�
void ChineseChess::setMode()
{
	//�D��椶��
	menuprint();
	while (true)
	{
		//�����O�_����L��J
		if (_kbhit())
		{
			int input = getch();
			//��J�䬰��V��
			if (input == 224)
			{
				input = getch();
				//��J�䬰UP
				if (input == 72)
				{
					up_gotoxy(gameMode);
					if (gameMode == 0)
						gameMode = 3;
					else
						gameMode--;
				}
				//��J�䬰DOWN
				else if (input == 80)
				{
					down_gotoxy(gameMode);
					if (gameMode == 3)
						gameMode = 0;
					else
						gameMode++;
				}
			}
			//��J�䬰ENTER
			else if (input == 13)
			{
				//�T�{�Ҧ��A���X���
				system("color 0f");
				system("cls");
				break;
			}
		}
	}
	//����ʧ@
	action();
}

//intent:�̷ӨϥΪ̿�ܼҦ��i��ʧ@
//pre:�ϥΪ̤w��ܼҦ�
//post:�̷ӿ�ܼҦ��i��ʧ@
void ChineseChess::action()
{
	int setFileFlag = 0;
	if (gameMode == 1)
	{
		//�q����Ū���ѽL
		setFileFlag = setPlayBoard("oldBoard.txt");
		//���\Ū���ѽL
		if (setFileFlag)
			playGame();
	}
	else if (gameMode == 2)

		getManual();
	else if (gameMode == 3)
		exitGame();
	else
	{
		//�зǴѧ�
		setFileFlag = setPlayBoard("initial.txt");
		//���\Ū���ѽL
		if (setFileFlag)
			playGame();
	}
	gameMode = 0;
}

//���o��l�ѧ��M�U�Ѥ�
bool ChineseChess::setPlayBoard(string file)
{
	ifstream inputFile(file);
	if (inputFile.is_open())
	{
		initialPlayBoard.resize(10);
		for (int i = 0; i < 10; i++)
		{
			initialPlayBoard[i].resize(9);
		}
		//���`�}��
		if (file == "initial.txt")
		{
			//�N�ɮפ��eŪ����vector
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					inputFile >> initialPlayBoard[i][j];
				}
			}
			inputFile >> initialTurn;
			return 1;
		}
		//�ݧ�
		else
		{
			//Ū���Ҧ��ݧ�
			vector<vector<vector<int>>> allBoard;
			vector<vector<int>> tmpBoard;
			vector<bool> allTurn;
			bool tmpTurn;
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
			//��ܴݧ�
			bool chooseFile = 0;
			int index = 0;
			load(allBoard.size());
			while (true)
			{
				if (_kbhit())
				{
					int input = getch();
					//�S��\����
					if (input == 224)
					{
						input = getch();
						//UP
						if (input == 72)
						{
							load_up_gotoxy(index, allBoard.size() - 1);
							if (index == 0)
								index = allBoard.size() - 1;
							else
								index--;
						}
						//DOWN
						else if (input == 80)
						{
							load_down_gotoxy(index, allBoard.size() - 1);
							if (index == allBoard.size() - 1)
								index = 0;
							else
								index++;
						}
					}
					else if (input == 13)
					{
						initialPlayBoard = allBoard[index];
						initialTurn = allTurn[index];
						printBoard();
						while (true)
						{
							if (_kbhit())
							{
								input = getch();
								//�T�w��ܦ��ѽL�i��C��
								if (input == 13)
								{
									system("color 0f");
									system("cls");
									return 1;
								}
								//���s���
								else if (input == 'q')
								{
									for (int j = 5; j < 24; j++) { gotoxy(45, j);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	cout << "                                     "; }
									gotoxy(117, 29);
									break;
								}
								else if (input == 27)
									return 0;
							}
						}
					}
					else if (input == 27)
						return 0;
				}
			}
		}
	}
	else
	{
		cout << "�S���´ѧ�" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	inputFile.close();
}

//intent:��ܻ���
//pre:����w�إ�
//post:���ChineseChess���k����
void ChineseChess::getManual()
{
	system("mode con cols=120 lines=30");
	ifstream manualFile("manual.txt");
	if (manualFile.is_open())
	{
		string buffer;
		while (!manualFile.eof())
		{
			for (int i = 0; i < 30 && getline(manualFile, buffer); i++)
			{
				cout << buffer << endl;
			}
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "�W�h�����ɿ�" << endl;
		system("pause");
		system("cls");
	}
	manualFile.close();
}

//intent:���}�C��
//pre:����w�إ�
//post:��X�T�������}�C��
void ChineseChess::exitGame()
{
	system("cls");
	gotoxy(28, 7);	cout << "      [33m                          �� ��                       [37m       ";
	gotoxy(28, 8);		cout << "    [1m                 ���i�i�i�i�i�i�i�i�i�i                 [m   ";
	gotoxy(28, 9);		cout << "[1m                   ���i�i�i�i�i�i�i�i�i�i�i                 [m   ";
	gotoxy(28, 10);		cout << "[1m                   �i�i�i�i�i�i�i�i�i�i�i�i                [m      ";
	gotoxy(28, 11);		cout << "[1m                   �i                �i�i�i               [m      ";
	gotoxy(28, 12);		cout << "[1m                   �i  �Q�I��O�i    �i�i�i               [m       ";
	gotoxy(28, 13);		cout << "[1m                   �i  �C���A�]��    �i�i�i  (���q���I)   [m       ";
	gotoxy(28, 14);		cout << "[1m         ���g�f�I  �i                �i�i�i               [m       ";
	gotoxy(28, 15);		cout << "[1m                   �i  �ں��o~~~     �i�i�i               [m    ";
	gotoxy(28, 16);		cout << "[1m     [33m���i�i��[37m��     �i                �i�i�i               [m     ";
	gotoxy(28, 17);		cout << "[1m     [33m�i[m�� ��[1;33m �j[37m    �i                �i�i�i               [m  ";
	gotoxy(28, 18);		cout << "[1m     [33m��[m���s��[1;33m�j[37m    �i�i�i�i�i�i�i�i�i�i���i               [m    ";
	gotoxy(28, 19);		cout << "[1m     ��   ����  �d   �i                �i                   [m  ";
	gotoxy(28, 20);		cout << "[1m    ����  �â�     �i                �i                   [m ";
	gotoxy(28, 21);		 cout << "[1m     �U    �U                                            [m   ";
	gotoxy(28, 22);		cout << "[1m      ���â�                                           [m      ";
	gotoxy(28, 23);		cout << "                                   [1;31m  No Time no see ���I[m      ";		
	gotoxy(97, 29);
	system("pause");
	exit(1);
}

void ChineseChess::printBoard(void)
{
	int x = 41, y = 3;
	board_basic(45, 5);
	for (int i = 0; i < 10; i++)
	{
		y = y + 2;	
		gotoxy(x, y);
		for (int j = 0; j < 9; j++)
		{
			x = x + 4;		 gotoxy(x, y);
			switch (initialPlayBoard[i][j])
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
		x = 41;	
	}
	gotoxy(117, 29);
}

