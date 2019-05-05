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

//intent:進行遊戲
//pre:傳入棋局
//post:回傳棋局結果
void ChineseChess::playGame()
{
	//初始化棋局
	ChessBoard board(initialPlayBoard,initialTurn);
	initial_start();
	board.saveBoard();
	board.printBoard();		gotoxy(34, 20);
	//是否已選棋
	bool haveChose = 0;
	bool chooseKing = 0;
	//選擇棋種
	chessBasic *chess = NULL;
	while (true)
	{
		//偵測鍵盤是否有輸入
		if (_kbhit())
		{
			int input = _getch();
			//輸入方向鍵
			if (input == 224)
			{
				//依照方向鍵改變座標
				board.changeCoordinate();
			}
			//輸入ENTER
			else if (input == 13)
			{
				//若未選擇棋子，進行選棋
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
							chooseKing = 1;
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
				//已選擇棋子，進行移動
				else
				{
					//可移動到目標座標
					if (chess->isMovable(board.getCurX(), board.getCurY(), board.getBoard()))
					{
						int haveWin = 0;
						//進行移動
						haveWin = board.move(chess);
						if (chooseKing)
						{
							if (board.kingMeetKing(board.getBoard()))
							{
								if (board.getTurn())
									haveWin = 1;
								else
									haveWin = 2;
							}
						}
						//改變選棋狀態
						haveChose = 0;
						//儲存棋局
						board.saveBoard();
						//換另一方動作
						board.changeTurn();
						board.printBoard();
						//判斷勝負狀態
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
			//輸入ESC
			else if (input == 27)
			{
				int leaveFlag;
				leaveFlag = board.menu();
				if (leaveFlag == 1)				//投降
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
				else if (leaveFlag == 2)		//說明書---------------------------------------讀完沒回原棋盤???
				{
					system("cls");	caption();
				}
				else if (leaveFlag == 3)		//離開
					exitGame();
			}
			else if(input=='q')
				haveChose = 0;
		}
	}
}

//intent:設定執行的動作
//pre:物件已建立
//post:儲存使用者選擇的模式
void ChineseChess::setMode()
{
	menuprint();
	while (true)
	{
		//偵測是否有鍵盤輸入
		if (_kbhit())
		{
			int input = _getch();
			//輸入鍵為方向鍵
			if (input == 224)
			{
				input = _getch();
				//輸入鍵為UP
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
				//輸入鍵為DOWN
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
			//輸入鍵為ENTER
			else if (input == 13)
			{
				//確認模式，跳出選擇
				system("color 0f");
				system("cls");
				break;
			}
		}
	}
	//執行動作
	action();
}

//intent:依照使用者選擇模式進行動作
//pre:使用者已選擇模式
//post:依照選擇模式進行動作
void ChineseChess::action()
{
	int setFileFlag = 0;
	if (gameMode == 1)
	{
		setFileFlag = setPlayBoard("oldBoard.txt");
		if (setFileFlag)
			playGame();
	}
	else if (gameMode == 2)
		caption();
	else if (gameMode == 3)
		exitGame();
	else
	{
		setFileFlag = setPlayBoard("initial.txt");
		if (setFileFlag)
			playGame();
	}
	gameMode = 0;
}

//取得初始棋局和下棋方
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
		//正常開局
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
			return 1;
		}
		//殘局
		else
		{
			//讀取所有殘局
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
			//選擇殘局
			bool chooseFile = 0;
			int index = 0;
			//檔案列表畫面
			while (true)
			{
				if (_kbhit())
				{
					int input = _getch();
					if (input == 224)
					{
						input = _getch();
						if (input == 72)
						{
							if (index == 0)
								index = 0;
							else
								index--;
						}
						else if (input == 80)
						{
							if (index == allBoard.size() - 1)
								index = allBoard.size() - 1;
							else
								index++;
						}
					}
					else if (input == 13)
					{
						initialPlayBoard = allBoard[index];
						initialTurn = allTurn[index];
						printBoard();
						input = _getch();
						while (true)
						{
							if (_kbhit())
							{
								if (input == 13)
									return 1;
								else if (input == 27)
									break;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		cout << "載入棋局失敗" << endl;
		system("pause");
		return 0;
	}
	inputFile.close();
}


//intent:離開遊戲
//pre:物件已建立
//post:輸出訊息並離開遊戲
void ChineseChess::exitGame()
{
	exit(0);
}

void ChineseChess::printBoard(void)
{
	int x = 30, y = 0;
	initial_start();
	for (int i = 0; i < 10; i++)
	{
		y = y + 2;	gotoxy(x, y);
		for (int j = 0; j < 9; j++)
		{
			x = x + 4;		 gotoxy(x, y);
			switch (initialPlayBoard[i][j])
			{
			case 1: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "將";	break; }
			case 2: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "士";	break; }
			case 3: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "象";	break; }
			case 4: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "車";	break; }
			case 5: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "馬";	break; }
			case 6: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "包";	break; }
			case 7: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "卒";	break; }
			case 8: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "帥";	break; }
			case 9: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "仕";	break; }
			case 10: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "相";	break; }
			case 11: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "��";	break; }
			case 12: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "傌";	break; }
			case 13: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "炮";	break; }
			case 14: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "兵";	break; }
			}
		}
		x = 30;	gotoxy(34, 20);
	}
	if (initialTurn)
	{
		//cout << "紅方下棋" << endl;
	}
	else
	{
		//cout << "黑方下棋" << endl;
	}
}

