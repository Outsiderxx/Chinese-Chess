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
	ChessBoard board(playBoard,turn);
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
						haveWin = board.move(chess,board.getCurX(),board.getCurY());
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
				board.menu();
			}
		}
	}
}

//intent:依照使用者選擇模式進行動作
//pre:使用者已選擇模式
//post:依照選擇模式進行動作
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
					if (this->gameMode == 0)
						this->gameMode = 3;
					else
						this->gameMode--;
				}
				//輸入鍵為DOWN
				else if (input == 80)
				{
					if (this->gameMode == 3)
						this->gameMode = 0;
					else
						this->gameMode++;
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