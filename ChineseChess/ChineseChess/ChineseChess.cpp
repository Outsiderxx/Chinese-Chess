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
	board.saveBoard();
	board.printBoard();
	//�O�_�w���
	bool haveChose = 0;
	//��ܴѺ�
	chessBasic *chess = NULL;
	while (true)
	{
		//������L�O�_����J
		if (kbhit())
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
					if (((board.getTurn() && board.getChess() > 7) || (!board.getTurn() && board.getChess() < 8)) && board.getChess() != 0)
					{
						haveChose = 1;
						int chessType = board.getChess() - board.getTurn() * 7;
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
						chess->setx(board.getCurX());
						chess->sety(board.getCurY());
						chess->setCamp(board.getTurn());
					}
				}
				//�w��ܴѤl�A�i�沾��
				else
				{
					//�i���ʨ�ؼЮy��
					if (chess->isMovable(board.getCurX(), board.getCurY(), board.getBoard()))
					{
						int haveWin = 0;
						//�i�沾��
						haveWin = board.move(chess);
						//���ܿ�Ѫ��A
						haveChose = 0;
						//�x�s�ѧ�
						board.saveBoard();
						//���t�@��ʧ@
						board.changeTurn();
						system("cls");
						board.printBoard();
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
			//��JESC
			else if (input == 27)
			{
				int leaveFlag;
				leaveFlag = board.menu();
				if (leaveFlag == 0)
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
				else if (leaveFlag == 1)
					getManual();
				else if (leaveFlag == 2)
					exitGame();
				else if (leaveFlag == 3)
					board.regret();
			}
			else if(input=='q')
				haveChose = 0;
		}
	}
}

//intent:�]�w���檺�ʧ@
//pre:����w�إ�
//post:�x�s�ϥΪ̿�ܪ��Ҧ�
void ChineseChess::setMode()
{
	while (true)
	{
		//�����O�_����L��J
		if (kbhit())
		{
			int input = getch();
			//��J�䬰��V��
			if (input == 224)
			{
				input = getch();
				//��J�䬰UP
				if (input == 72)
				{
					if (gameMode == 0)
						gameMode = 0;
					else
					{
						gameMode--;
						up_gotoxy(gameMode);
					}
				}
				//��J�䬰DOWN
				else if (input == 80)
				{
					if (gameMode == 3)
						gameMode = 3;
					else
					{
						gameMode++;
						down_gotoxy(gameMode);
					}
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
}

//intent:�̷ӨϥΪ̿�ܼҦ��i��ʧ@
//pre:�ϥΪ̤w��ܼҦ�
//post:�̷ӿ�ܼҦ��i��ʧ@
void ChineseChess::action()
{
	if (gameMode == 1)
	{
		setPlayBoard("oldBoard.txt");
		playGame();
	}
	else if (gameMode == 2)
		caption();
	else if (gameMode == 3)
		exitGame();
	else
	{
		setPlayBoard("initial.txt");
		playGame();
	}
	gameMode = 0;
}

//���o��l�ѧ��M�U�Ѥ�
void ChineseChess::setPlayBoard(string file)
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
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					inputFile >> initialPlayBoard[i][j];
				}
			}
			inputFile >> initialTurn;
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
							if (index == 0)
								index = allBoard.size() - 1;
							else
								index--;
						}
						else if (input == 80)
						{
							if (index == allBoard.size() - 1)
								index = 0;
							else
								index++;
						}
					}
					else if (input == 13)
					{
						if (chooseFile)
						{
							initialPlayBoard = allBoard[index];
							initialTurn = allTurn[index];
							break;
						}
						else
						{
							//��X�ݧ��w���e��
							input = getch();
							if (input == 13)
								chooseFile = 1;
						}
					}
					else if (input == 27)
					{
						if (chooseFile)
							chooseFile = 0;
					}
				}
			}
		}
	}
	else
		cout << "���J�ѧ�����" << endl;
	inputFile.close();
}

//intent:��ܻ���
//pre:����w�إ�
//post:���ChineseChess���k����
void ChineseChess::getManual()
{
	ifstream manualFile("manual.txt");
	if (manualFile.is_open())
		cout << manualFile.rdbuf();
	else
		cout << "open manual fail" << endl;
	manualFile.close();
}

//intent:���}�C��
//pre:����w�إ�
//post:��X�T�������}�C��
void ChineseChess::exitGame()
{
	cout << "Good bye!" << endl;
	exit(1);
}

