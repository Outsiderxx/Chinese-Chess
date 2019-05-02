#include <iostream>
#include <fstream>
#include <conio.h>
#include "ChineseChess.h"
#include "ChessBoard.h"
#include "chessBasic.h"
using namespace std;

//intent:�i��C��
//pre:�ǤJ�ѧ�
//post:�^�Ǵѧ����G
void ChineseChess::playGame()
{
	//��l�ƴѧ�
	ChessBoard board(initialPlayBoard,initialTurn);
	//�O�_�w���
	bool haveChose = 0;
	//�ثe�U�Ѥ�
	bool nowTurn = board.getTurn();
	//��ܴѺ�
	chessBasic *chess;
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
					//��ܴѤl
					bool chooseFlag = 0;
					chooseFlag = board.chooseChess(&chess);
					if(chooseFlag)
						haveChose = 1;
				}
				//�w��ܴѤl�A�i�沾��
				else
				{
					//�i���ʨ�ؼЮy��
					if (chess->isMovable())
					{
						int haveWin = 0;
						//�i�沾��
						haveWin = board.move(chess);
						//�P�_�ӭt���A
						if (haveWin == 1)
						{
							cout << "�¤��" << endl;
							break;
						}
						else if (haveWin == 2)
						{
							cout << "�����" << endl;
							break;
						}
						//���ܿ�Ѫ��A
						haveChose = 0;
						//�x�s�ѧ�
						board.saveBoard();
						//���t�@��ʧ@
						board.changeTurn();
					}
				}
			}
			//��JESC
			else if (input == 27)
			{
				int leaveFlag;
				leaveFlag = board.menu();
				if (leaveFlag == 1)
					exitGame();
				else if (leaveFlag == 2)
					getManual();
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
		getManual();
	else if (gameMode == 3)
		exitGame();
	else
	{
		setPlayBoard("initial.txt");
		playGame();
	}
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
						gameMode = 3;
					else
						gameMode--;
				}
				//��J�䬰DOWN
				else if (input == 80)
				{
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
				break;
			}
		}
	}
}

//���o��l�ѧ��M�U�Ѥ�
void ChineseChess::setPlayBoard(string file)
{
	ifstream inputFile(file);
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
	inputFile.close();
}