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
	board.saveBoard();
	board.printBoard();
	//是否已選棋
	bool haveChose = 0;
	//選擇棋種
	chessBasic *chess = NULL;
	while (true)
	{
		//偵測鍵盤是否有輸入
		if (kbhit())
		{
			int input = getch();
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
						//改變選棋狀態
						haveChose = 0;
						//儲存棋局
						board.saveBoard();
						//換另一方動作
						board.changeTurn();
						system("cls");
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

//intent:設定執行的動作
//pre:物件已建立
//post:儲存使用者選擇的模式
void ChineseChess::setMode()
{
	while (true)
	{
		//偵測是否有鍵盤輸入
		if (kbhit())
		{
			int input = getch();
			//輸入鍵為方向鍵
			if (input == 224)
			{
				input = getch();
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
}

//intent:依照使用者選擇模式進行動作
//pre:使用者已選擇模式
//post:依照選擇模式進行動作
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

//取得初始棋局和下棋方
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
							//輸出殘局預覽畫面
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
		cout << "載入棋局失敗" << endl;
	inputFile.close();
}

//intent:顯示說明
//pre:物件已建立
//post:顯示ChineseChess玩法說明
void ChineseChess::getManual()
{
	ifstream manualFile("manual.txt");
	if (manualFile.is_open())
		cout << manualFile.rdbuf();
	else
		cout << "open manual fail" << endl;
	manualFile.close();
}

//intent:離開遊戲
//pre:物件已建立
//post:輸出訊息並離開遊戲
void ChineseChess::exitGame()
{
	cout << "Good bye!" << endl;
	exit(1);
}

