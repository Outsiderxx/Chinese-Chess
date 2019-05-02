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
bool ChineseChess::playGame(string chessBoard)
{
	//��l�ƴѧ�
	ChessBoard board(chessBoard);
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
					board.chooseChess(chess);
					//���ܿ�Ѫ��A
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
						haveWin = board.move();
						//�P�_�ӭt���A
						if (haveWin == 1)
							return 0;
						else if (haveWin == 2)
							return 1;
						//���ܿ�Ѫ��A
						haveChose = 0;
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

	}
	else if (this->gameMode == 2)
		this->getManual();
	else if (this->gameMode == 3)
		this->exitGame();
	else
		this->playGame("initial.txt");
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