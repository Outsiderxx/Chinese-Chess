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

//intent:¶i¦æ¹CÀ¸
//pre:¶Ç¤J´Ñ§½
//post:¦^¶Ç´Ñ§½µ²ªG
void ChineseChess::playGame()
{
	//ªì©l¤Æ´Ñ§½
	ChessBoard board(initialPlayBoard,initialTurn);
	initial_start();
	//¬O§_¤w¿ï´Ñ
	bool haveChose = 0;
	gotoxy(34, 20);
	//Àx¦s´Ñ½L
	board.saveBoard();
	//¿é¥X´Ñ½L
	board.printBoard();
	//´Ñ¤l
	chessBasic *chess = NULL;
	while (true)
	{
		//°»´úÁä½L¬O§_¦³¿é¤J
		if (_kbhit())
		{
			int input = getch();
			//¿é¤J¤è¦VÁä
			if (input == 224)
			{
				//¨Ì·Ó¤è¦VÁä§ïÅÜ®y¼Ð
				board.changeCoordinate();
			}
			//¿é¤JENTER
			else if (input == 13)
			{
				//­Y¥¼¿ï¾Ü´Ñ¤l¡A¶i¦æ¿ï´Ñ
				if (!haveChose)
				{
					King kingChess;
					Counselor counselorChess;
					Elephant elephantChess;
					Car carChess;
					Horse horseChess;
					bubble bubbleChess;
					slave slaveChess;
					//§PÂ_¿ï¨úªººX¤l¬O§_¬°¤v¤è
					if (((board.getTurn() && board.getChess(board.getCurY(),board.getCurX()) > 7) || (!board.getTurn() && board.getChess(board.getCurY(), board.getCurX()) < 8)) && board.getChess(board.getCurY(), board.getCurX()) != 0)
					{
						//¤w¿ï¾Ü´Ñ¤l
						haveChose = 1;
						gotoxy(85, 8);
						int chessType = board.getChess(board.getCurY(), board.getCurX()) - board.getTurn() * 7;
						board.printChess(chessType);
						//®Ú¾Ú´Ñ½L¤Wªº¼Æ¦r¡A¿ï¾Ü¹ïÀ³ªº´Ñ¤l
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
						//³]©w´Ñ¤l®y¼Ð°}Àç
						chess->setx(board.getCurX());
						chess->sety(board.getCurY());
						chess->setCamp(board.getTurn());
						gotoxy(34 + 4 * board.getCurX(), 2 + 2 * board.getCurY());
					}
				}
				//¤w¿ï¾Ü´Ñ¤l¡A¶i¦æ²¾°Ê
				else
				{
					//¥i²¾°Ê¨ì¥Ø¼Ð®y¼Ð
					if (chess->isMovable(board.getCurX(), board.getCurY(), board.getBoard()))
					{
						int haveWin = 0;
						//¾ÔªpÅã¥Ü
						board.printStatus(chess->getx(),chess->gety());
						//¶i¦æ²¾°Ê
						haveWin = board.move(chess);
						//¬O§_¦³¤ý¹ï¤ý±¡ªp¥X²{
						if (board.kingMeetKing(board.getBoard()))
						{
							//¤ý¹ï¤ý¥X²{®É¡A¹ï¤è³Ó§Q
							if (board.getTurn())
								haveWin = 1;
							else
								haveWin = 2;
						}
						//§ïÅÜ¿ï´Ñª¬ºA
						haveChose = 0;
						//Àx¦s´Ñ§½
						board.saveBoard();
						//´«¥t¤@¤è°Ê§@
						board.changeTurn();
						//¿é¥X´Ñ§½
						board.printBoard();
						gotoxy(85, 8);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						cout << "                     ";
						gotoxy(34 + 4 * board.getCurX(), 2 + 2 * board.getCurY());
						//§PÂ_³Ó­tª¬ºA
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
			//¥s¥X¿ï³æ
			else if (input == 27)
			{
				int leaveFlag;
				leaveFlag = board.menu();
				//¿ï¾Ü§ë­°¡A¹ï¤è³Ó§Q
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
				//Åã¥Ü»¡©ú®Ñ
				else if (leaveFlag == 2)
				{
					system("cls");
					getManual();
					initial_start();
					board.printBoard();
				}
				//Â÷¶}¹CÀ¸
				else if (leaveFlag == 3)
					exitGame();
			}
			//¨ú®ø¿ï¾Ü´Ñ¤l
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

//intent:³]©w°õ¦æªº°Ê§@
//pre:ª«¥ó¤w«Ø¥ß
//post:Àx¦s¨Ï¥ÎªÌ¿ï¾Üªº¼Ò¦¡
void ChineseChess::setMode()
{
	//¥D¿ï³æ¤¶­±
	menuprint();
	while (true)
	{
		//°»´ú¬O§_¦³Áä½L¿é¤J
		if (_kbhit())
		{
			int input = getch();
			//¿é¤JÁä¬°¤è¦VÁä
			if (input == 224)
			{
				input = getch();
				//¿é¤JÁä¬°UP
				if (input == 72)
				{
					up_gotoxy(gameMode);
					if (gameMode == 0)
						gameMode = 3;
					else
						gameMode--;
				}
				//¿é¤JÁä¬°DOWN
				else if (input == 80)
				{
					down_gotoxy(gameMode);
					if (gameMode == 3)
						gameMode = 0;
					else
						gameMode++;
				}
			}
			//¿é¤JÁä¬°ENTER
			else if (input == 13)
			{
				//½T»{¼Ò¦¡¡A¸õ¥X¿ï¾Ü
				system("color 0f");
				system("cls");
				break;
			}
		}
	}
	//°õ¦æ°Ê§@
	action();
}

//intent:¨Ì·Ó¨Ï¥ÎªÌ¿ï¾Ü¼Ò¦¡¶i¦æ°Ê§@
//pre:¨Ï¥ÎªÌ¤w¿ï¾Ü¼Ò¦¡
//post:¨Ì·Ó¿ï¾Ü¼Ò¦¡¶i¦æ°Ê§@
void ChineseChess::action()
{
	int setFileFlag = 0;
	if (gameMode == 1)
	{
		//±qÂÂÀÉÅª¨ú´Ñ½L
		setFileFlag = setPlayBoard("oldBoard.txt");
		//¦¨¥\Åª¨ú´Ñ½L
		if (setFileFlag)
			playGame();
	}
	else if (gameMode == 2)

		getManual();
	else if (gameMode == 3)
		exitGame();
	else
	{
		//¼Ð·Ç´Ñ§½
		setFileFlag = setPlayBoard("initial.txt");
		//¦¨¥\Åª¨ú´Ñ½L
		if (setFileFlag)
			playGame();
	}
	gameMode = 0;
}

//¨ú±oªì©l´Ñ§½©M¤U´Ñ¤è
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
		//¥¿±`¶}§½
		if (file == "initial.txt")
		{
			//±NÀÉ®×¤º®eÅª¨ú¨ìvector
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
		//´Ý§½
		else
		{
			//Åª¨ú©Ò¦³´Ý§½
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
				//±NÀÉ®×¤º®eÅª¨ú¨ìvector
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
			//¿ï¾Ü´Ý§½
			bool chooseFile = 0;
			int index = 0;
			load(allBoard.size());
			while (true)
			{
				if (_kbhit())
				{
					int input = getch();
					//¯S®í¥\¯àÁä
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
								//½T©w¿ï¾Ü¦¹´Ñ½L¶i¦æ¹CÀ¸
								if (input == 13)
								{
									system("color 0f");
									system("cls");
									return 1;
								}
								//­«·s¿ï¾Ü
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
		cout << "¨S¦³ÂÂ´Ñ§½" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	inputFile.close();
}

//intent:Åã¥Ü»¡©ú
//pre:ª«¥ó¤w«Ø¥ß
//post:Åã¥ÜChineseChessª±ªk»¡©ú
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
		cout << "³W«h»¡©úÀÉ¿ò¥¢" << endl;
		system("pause");
		system("cls");
	}
	manualFile.close();
}

//intent:Â÷¶}¹CÀ¸
//pre:ª«¥ó¤w«Ø¥ß
//post:¿é¥X°T®§¨ÃÂ÷¶}¹CÀ¸
void ChineseChess::exitGame()
{
	system("cls");
	gotoxy(28, 7);	cout << "      [33m                          ¢­ ¡þ                       [37m       ";
	gotoxy(28, 8);		cout << "    [1m                 ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i                 [m   ";
	gotoxy(28, 9);		cout << "[1m                   ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i                 [m   ";
	gotoxy(28, 10);		cout << "[1m                   ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i                [m      ";
	gotoxy(28, 11);		cout << "[1m                   ¢i                ¢i¢i¢i               [m      ";
	gotoxy(28, 12);		cout << "[1m                   ¢i  ¤QÂI«á§O¶i    ¢i¢i¢i               [m       ";
	gotoxy(28, 13);		cout << "[1m                   ¢i  ¹CÀ¸¡A¦]¬°    ¢i¢i¢i  (Ãö¹q¸£¡I)   [m       ";
	gotoxy(28, 14);		cout << "[1m         ¯«¸g¯f¡I  ¢i                ¢i¢i¢i               [m       ";
	gotoxy(28, 15);		cout << "[1m                   ¢i  §ÚºÎÅo~~~     ¢i¢i¢i               [m    ";
	gotoxy(28, 16);		cout << "[1m     [33m¢¨¢i¢i¢©[37m¢£     ¢i                ¢i¢i¢i               [m     ";
	gotoxy(28, 17);		cout << "[1m     [33m¢i[m£¿ £½[1;33m ¢j[37m    ¢i                ¢i¢i¢i               [m  ";
	gotoxy(28, 18);		cout << "[1m     [33m¢«[m¡¼¡s¡¼[1;33m¢j[37m    ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«¢i               [m    ";
	gotoxy(28, 19);		cout << "[1m     ¢­   ¢²¢¬  ¢d   ¢i                ¢i                   [m  ";
	gotoxy(28, 20);		cout << "[1m    ¢¨¡Ã  ¡Ã¢«     ¢i                ¢i                   [m ";
	gotoxy(28, 21);		 cout << "[1m     ¡U    ¡U                                            [m   ";
	gotoxy(28, 22);		cout << "[1m      ¢«¡Ã¢ª                                           [m      ";
	gotoxy(28, 23);		cout << "                                   [1;31m  No Time no see »¶¡I[m      ";		
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
			case 1: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "±N";	break; }
			case 2: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "¤h";	break; }
			case 3: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "¶H";	break; }
			case 4: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "¨®";	break; }
			case 5: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "°¨";	break; }
			case 6: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "¥]";	break; }
			case 7: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); cout << "¨ò";	break; }
			case 8: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "«Ó";	break; }
			case 9: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "¥K";	break; }
			case 10: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "¬Û";	break; }
			case 11: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "¨®";	break; }
			case 12: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "ØX";	break; }
			case 13: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "¬¶";	break; }
			case 14: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "§L";	break; }
			}
		}
		x = 41;	
	}
	gotoxy(117, 29);
}

