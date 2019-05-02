#include <iostream>
#include <fstream>
#include <conio.h>
#include "ChineseChess.h"
#include "ChessBoard.h"
#include "chessBasic.h"
using namespace std;

//intent:進行遊戲
//pre:傳入棋局
//post:回傳棋局結果
void ChineseChess::playGame()
{
	//初始化棋局
	ChessBoard board(initialPlayBoard,initialTurn);
	//是否已選棋
	bool haveChose = 0;
	//目前下棋方
	bool nowTurn = board.getTurn();
	//選擇棋種
	chessBasic *chess;
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
					//選擇棋子
					bool chooseFlag = 0;
					chooseFlag = board.chooseChess(&chess);
					if(chooseFlag)
						haveChose = 1;
				}
				//已選擇棋子，進行移動
				else
				{
					//可移動到目標座標
					if (chess->isMovable())
					{
						int haveWin = 0;
						//進行移動
						haveWin = board.move(chess);
						//判斷勝負狀態
						if (haveWin == 1)
						{
							cout << "黑方勝" << endl;
							break;
						}
						else if (haveWin == 2)
						{
							cout << "紅方勝" << endl;
							break;
						}
						//改變選棋狀態
						haveChose = 0;
						//儲存棋局
						board.saveBoard();
						//換另一方動作
						board.changeTurn();
					}
				}
			}
			//輸入ESC
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
		getManual();
	else if (gameMode == 3)
		exitGame();
	else
	{
		setPlayBoard("initial.txt");
		playGame();
	}
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
						gameMode = 3;
					else
						gameMode--;
				}
				//輸入鍵為DOWN
				else if (input == 80)
				{
					if (gameMode == 3)
						gameMode = 0;
					else
						gameMode++;
				}
			}
			//輸入鍵為ENTER
			else if (input == 13)
			{
				//確認模式，跳出選擇
				break;
			}
		}
	}
}

//取得初始棋局和下棋方
void ChineseChess::setPlayBoard(string file)
{
	ifstream inputFile(file);
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
	inputFile.close();
}