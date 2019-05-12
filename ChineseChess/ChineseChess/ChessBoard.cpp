#include <fstream>
#include <conio.h>
#include "ChessBoard.h"
#include "start_menu.h"
#include "menu_operate.h"

//初始化棋局和下棋方
ChessBoard::ChessBoard(vector<vector<int>> chessBoard,bool nowTurn)
{
	curX = 0;
	if (nowTurn == 0)
		curY = 0;
	else
		curY = 9;
	curBoard.resize(10);
	for (int i = 0; i < 10; i++)
	{
		curBoard[i].resize(9);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			curBoard[i][j] = chessBoard[i][j];
		}
	}
	turn = nowTurn;
}

//取得當前座標棋子種類
int ChessBoard::getChess(int coorY,int coorX)
{
	return curBoard[coorY][coorX];
}

//取得下棋方
bool ChessBoard::getTurn(void)
{
	return turn;
}

//改變下棋方
void ChessBoard::changeTurn(void)
{
	turn = 1 - turn;
}

//取得當前游標X座標
int ChessBoard::getCurX(void)
{
	return curX;
}

//取得當前游標Y座標
int ChessBoard::getCurY(void)
{
	return curY;
}

//移動游標位置
void ChessBoard::changeCoordinate(void)
{
	int direction = _getch();
	switch (direction)
	{
	//UP
	case 72:
		if (curY > 0) { curY--;	gotoxy(34 + curX * 4, 2 + curY * 2); }	
		break;
	//DOWN
	case 80:
		if (curY < 9) { curY++;	gotoxy(34 + curX * 4, 2 + curY * 2); }
		break;
	//LEFT
	case 75:
		if (curX > 0) { curX--;	gotoxy(34 + curX * 4, 2 + curY * 2); }	
		break;
	//RIGHT
	case 77:
		if (curX < 8) { curX++; gotoxy(34 + curX * 4, 2 + curY * 2); }	
		break;
	default:	
		break;
	}
}

//顯示菜單
//toDo=0 繼續 toDo=1 存檔 toDo=2 投降 toDo=3 說明 toDo=4 悔棋 toDo=5 離開遊戲 ---------------------------------------未完成
int ChessBoard::menu(void)
{
	int toDo = 0;
	escmenu();					//ESC清單畫面
	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == 224)
			{
				input = _getch();
				if (input == 75)			//左
				{
					if (toDo == 0)
						toDo = 0;
					else
					{
						toDo--;
						esc_left_gotoxy(toDo);
					}
				}
				else if (input == 77)		//右
				{
					if (toDo == 5)
						toDo = 5;
					else
					{
						toDo++;
						esc_right_gotoxy(toDo);
					}
				}
			}
			else if (input == 13)		//enter確定選取
			{
				switch (toDo)			//做完動作清除選單畫面游標移到上一步位置
				{
				case 0: {	escclear();	gotoxy(34 + curX * 4, 2 + curY * 2); return 0; }
				case 1: {	saveFile();	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2);  return 0; }
				case 2: {	escclear();	gotoxy(34 + curX * 4, 2 + curY * 2); return 1; }
				case 3: {	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2); return 2; }
				case 4: {	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2); regret(); return 0; }		
				case 5: {	escclear(); gotoxy(34 + curX * 4, 2 + curY * 2); return 3; }
				}
			}
		}
	}
}

//移動棋子
int ChessBoard::move(chessBasic* curChess)
{
	int returnValue;
	if (getChess(curY, curX) == 1)
		returnValue = 2;
	else if(getChess(curY, curX) == 8)
		returnValue = 1;
	else
		returnValue = 0;
	curBoard[curY][curX] = curBoard[curChess->gety()][curChess->getx()];
	curBoard[curChess->gety()][curChess->getx()] = 0;
	curChess->setx(curX);
	curChess->sety(curY);
	return returnValue;
}

//儲存棋局
void ChessBoard::saveBoard(void)
{
	preBoard.push_back(curBoard);
}

//悔棋
void ChessBoard::regret(void)
{
	if (preBoard.size() > 2)
	{
		if (preBoard.size() % 12 == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(6, 3);
			cout << "                   ";
			gotoxy(6, 3 + 2 * 11);
			cout << "                   ";
		}
		else if (preBoard.size() % 12 == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(6, 3 + 2 * 10);
			cout << "                   ";
			gotoxy(6, 3 + 2 * 11);
			cout << "                   ";
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(6, 3 + (preBoard.size() % 12 - 2) * 2);
			cout << "                   ";
			gotoxy(6, 3 + (preBoard.size() % 12 - 2) * 2 - 2);
			cout << "                   ";
		}
		curBoard = preBoard[preBoard.size() - 3];
		printBoard();
		preBoard.pop_back();
		preBoard.pop_back();
	}
	else
	{
		gotoxy(90, 8);
		cout << "無法悔棋";
		gotoxy(85, 9);
		system("pause");
		gotoxy(90, 8);
		cout << "            ";
		gotoxy(85, 9);
		cout << "                     ";
		gotoxy(34 + 4 * curX, 2 + 2 * curY);
	}
}

//存檔
void ChessBoard::saveFile(void)
{
	vector<vector<vector<int>>> allBoard;
	vector<vector<int>> tmpBoard;
	vector<bool> allTurn;
	bool tmpTurn;
	ifstream inputFile("oldBoard.txt");
	tmpBoard.resize(10);
	for (int i = 0; i < 10; i++)
	{
		tmpBoard[i].resize(9);
	}
	while (true)
	{
		//將檔案內容讀取到vector
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
	inputFile.close();
	tmpBoard = curBoard;
	tmpTurn = turn;
	if (allBoard.size() == 10)
	{
		for (int i = 0; i < 9; i++)
		{
			allBoard[i] = allBoard[i + 1];
			allTurn[i] = allTurn[i + 1];
		}
		allBoard.pop_back();
		allTurn.pop_back();
	}
	allBoard.push_back(tmpBoard);
	allTurn.push_back(tmpTurn);
	ofstream outputFile("oldBoard.txt");
	for (int k = 0; k < allBoard.size(); k++)
	{
		for (int i = 0; i < 10; i++)
		{
			for(int j=0;j<9;j++)
			{
				outputFile << allBoard[k][i][j] << " ";
			}
			outputFile << endl;
		}
		outputFile << allTurn[k] << endl;
	}
}

vector<vector<int>> ChessBoard::getBoard(void)
{
	return curBoard;
}

void ChessBoard::printBoard(void)
{
	int x = 30, y = 0;
	board_basic(34, 2);
	for (int i = 0; i < 10; i++)
	{
		y = y + 2;	
		gotoxy(x, y);
		for (int j = 0; j < 9; j++)
		{
			x = x + 4;		
			gotoxy(x, y);
			switch (curBoard[i][j])
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
			case 11: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "車";	break; }
			case 12: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "傌";	break; }
			case 13: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "炮";	break; }
			case 14: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); cout << "兵";	break; }
			}
		}
		x = 30;
	}
	if (turn)
	{
		gotoxy(92, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	cout << "紅方下棋";
	}
	else
	{
		gotoxy(92, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);	 cout << "黑方下棋";
	}
	gotoxy(34 + curX * 4, 2 + curY * 2);
}

void ChessBoard::replay(void)
{
	curBoard = preBoard[0];
	printBoard();
	gotoxy(82, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
	gotoxy(85, 8);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~~~~重播中~~~~~~";
	gotoxy(85, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~按enter播下一手~~~";
	int index = 1;
	while (true)
	{
		if (index == preBoard.size())
		{
			gotoxy(85, 8);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
			gotoxy(85, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
			gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "重播結束~~";
			gotoxy(87, 11); system("pause");
			break;
		}
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13)
			{
				curBoard = preBoard[index];
				printBoard();
				index++;
				gotoxy(82, 4);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	 cout << "                           ";
				gotoxy(85, 8);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~~~~重播中~~~~~~";
				gotoxy(85, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	 cout << "~~~按enter播下一手~~~";
			}
		}
	}
}

void ChessBoard::win(bool whoWin)
{
	if (!whoWin)
	{
		gotoxy(82, 4); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	cout << "                             ";
		gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);	cout << "黑方勝 ! ! !" ;
	}
	else
	{
		gotoxy(82, 4); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	cout << "                             ";
		gotoxy(87, 10);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);	cout << "紅方勝 ! ! !" ;
	}
	gotoxy(82, 11);
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(82, 11);
	cout << "                         ";
	gotoxy(87, 10);
	cout << "                        ";
	gotoxy(80, 5);
	cout << " 是否要觀看重播 ";
	bool replayFlag = 1;
	gotoxy(94, 7);
	cout << "否(回主畫面)";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(90, 7);
	cout << "是";
	gotoxy(117, 29);
	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == 224)
			{
				input = _getch();
				if (input == 75)
					replay_left_gotoxy();
				else if (input == 77)
					replay_right_gotoxy();
				replayFlag = 1 - replayFlag;
			}
			else if (input == 13)
			{
				if (replayFlag)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(80, 5);
					cout << "                ";
					gotoxy(90, 7);
					cout << "                   ";
					replay();
				}
				break;
			}
		}
	}
}

bool ChessBoard::kingMeetKing(vector<vector<int>> board)	//king meet king
{
	int kingX1, kingX2, kingY1,kingY2;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 1)
			{
				kingY1 = i;
				kingX1 = j;
			}
			if (board[i][j] == 8)
			{
				kingY2 = i;
				kingX2 = j;
			}
		}
	}
	if (kingX1 == kingX2)
	{
		for (int loop=kingY1+1;loop<kingY2;loop++)
		{

			if (board[loop][kingX1] != 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

void ChessBoard::printChess(int chessType)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	const string chessName[15] = { "","將","士" ,"象" ,"車" ,"馬" ,"包" ,"卒" ,"帥" ,"仕" ,"相" ,"車" ,"傌" ,"炮" ,"兵" };
	if (!turn)
	{
		cout << "當前選擇的棋子是 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		cout << chessName[chessType];
	}
	else
	{
		cout << "當前選擇的棋子是 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		cout << chessName[chessType + 7];
	}
}

void ChessBoard::printStatus(int chessX, int chessY)
{
	int moveY = curY - chessY, chessType = getChess(chessY, chessX);
	const string number[10] = { "一","二","三","四","五","六","七","八","九" };
	const string chessName[15] = { "","將","士" ,"象" ,"車" ,"馬" ,"包" ,"卒" ,"帥" ,"仕" ,"相" ,"車" ,"傌" ,"炮" ,"兵" };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	if (preBoard.size() % 12 == 0)
		gotoxy(6, 3 + 2 * 11);
	else
		gotoxy(6, 3 + 2 * (preBoard.size() % 12 - 1));
	cout << preBoard.size() << " ";
	if (turn)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
		cout << "紅";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << " : " << chessName[chessType] << " " << number[8 - chessX];
		if (moveY < 0)
			cout << " 進 ";
		else if (moveY == 0)
			cout << " 平 ";
		else
			cout << " 退 ";
		if (chessType == 8 || chessType == 11 || chessType == 13 || chessType == 14)
		{
			if (moveY == 0)
				cout << number[8 - curX];
			else
			{
				if (moveY < 0)
					moveY *= -1;
				cout << number[moveY - 1];
			}
		}
		else
			cout << number[8 - curX];
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		cout << "黑";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << " : " << chessName[chessType] << "  " << chessX + 1;
		if (moveY > 0)
			cout << " 進  ";
		else if (moveY == 0)
			cout << " 平  ";
		else
			cout << " 退  ";
		if (chessType == 1 || chessType == 4 || chessType == 6 || chessType == 7)
		{
			if (moveY == 0)
				cout << curX + 1;
			else
			{
				if (moveY < 0)
					moveY *= -1;
				cout << moveY;
			}
		}
		else
			cout << curX + 1;
	}
}