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
	ChessBoard board(playBoard,turn);
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
						haveWin = board.move(chess,board.getCurX(),board.getCurY());
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
				board.menu();
			}
		}
	}
}

//intent:�̷ӨϥΪ̿�ܼҦ��i��ʧ@
//pre:�ϥΪ̤w��ܼҦ�
//post:�̷ӿ�ܼҦ��i��ʧ@
void ChineseChess::action()
{
	if (this->gameMode == 1)
	{
		this->setPlayBoard("oldBoard.txt");
	}
	else if (this->gameMode == 2)
		this->getManual();
	else if (this->gameMode == 3)
		this->exitGame();
	else
		this->setPlayBoard("initial.txt");
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
					if (this->gameMode == 0)
						this->gameMode = 3;
					else
						this->gameMode--;
				}
				//��J�䬰DOWN
				else if (input == 80)
				{
					if (this->gameMode == 3)
						this->gameMode = 0;
					else
						this->gameMode++;
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

void ChineseChess::setPlayBoard(string file)
{
	ifstream inputFile(file);
	if (file == "initial.txt")
	{
		playBoard.resize(9);
		for (int i = 0; i < 9; i++)
		{
			playBoard[i].resize(10);
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				inputFile >> playBoard[i][j];
			}
		}
		inputFile >> turn;
	}
	else
	{
		vector<vector<int>> tmp;
		bool tmpTurn;
		tmp.resize(9);
		for (int i = 0; i < 9; i++)
		{
			tmp[i].resize(10);
		}
	}
}