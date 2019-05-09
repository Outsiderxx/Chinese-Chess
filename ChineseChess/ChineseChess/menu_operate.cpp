#include "menu_operate.h"
#define initialx 17
#define initialy	 5

const string word[15] = { "","將","士" ,"象" ,"車" ,"馬" ,"包" ,"卒" ,"帥" ,"仕" ,"相" ,"車" ,"傌" ,"炮" ,"兵" };
const string ChessBoardword[10] = { " ChessBoard 1 : "," ChessBoard 2 : "," ChessBoard 3 : "," ChessBoard 4 : "," ChessBoard 5 : "," ChessBoard 6 : "," ChessBoard 7 : "," ChessBoard 8 : "," ChessBoard 9 : "," ChessBoard 10 : " };
const string escwords[6] = { "0繼續遊戲","1儲存檔案","2舉起白旗","3偷看說明","4可憐悔棋","5離開遊戲" };

void load(int boardNum)						//ChessBoard list
{
	const int row = 28, column = 117;
	/*外框*/
	gotoxy(0, 0);
	cout << "┌";
	for (int i = 1; i < column; i++)
		cout << "─";
	cout << "┐";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);
		cout << "│";
		gotoxy(column, i);
		cout << "│";
	}
	gotoxy(0, row);
	cout << "└";
	for (int i = 1; i < column; i++)
		cout << "─";
	cout << "┘";
	gotoxy(10, 2);
	cout << "------Select your record------";
	gotoxy(47, 2);
	cout << "------Chessboard Preview------";
	gotoxy(85, 5);
	cout << "Press ↑↓ 選擇要預覽的棋盤";
	gotoxy(85, 8);
	cout << "Press Enter 預覽棋盤/進入遊戲";
	gotoxy(85, 11);
	cout << "Press 'q' 選擇其他棋盤";
	gotoxy(85, 14);
	cout << "Press Esc 回到主畫面";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(initialx, initialy);
	cout << " ChessBoard 1";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 1; i < boardNum; i++)
	{
		gotoxy(initialx, initialy + i * 2);
		cout << " ChessBoard " << i + 1;
	}
	gotoxy(117, 29);
}

void board_basic(int boardx, int boardy)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardx, boardy);				cout << "╔ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╗ ";
	gotoxy(boardx, boardy + 1);			cout << "│ 　│ 　│   │ ╲ │ ╱ │ 　│ 　│ 　│ ";
	gotoxy(boardx, boardy + 2);			cout << "│ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ │ ";
	gotoxy(boardx, boardy + 3);			cout << "│ 　│ 　│   │ ╱ │ ╲ │ 　│ 　│ 　│ ";
	gotoxy(boardx, boardy + 4);			cout << "│ ─ ╬ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ╬ ─ │ ";
	gotoxy(boardx, boardy + 5);			cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardx, boardy + 6);			cout << "│ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ │ ";
	gotoxy(boardx, boardy + 7);			cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardx, boardy + 8);			cout << "│ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ │ ";
	gotoxy(boardx, boardy + 9);			cout << "│　　 　楚河　　　　　漢界　  　│ ";
	gotoxy(boardx, boardy + 10);		cout << "│ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ │ ";
	gotoxy(boardx, boardy + 11);		cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardx, boardy + 12);		cout << "│ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ │ ";
	gotoxy(boardx, boardy + 13);		cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardx, boardy + 14);		cout << "│ ─ ╬ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ╬ ─ │ ";
	gotoxy(boardx, boardy + 15);		cout << "│ 　│ 　│   │ ╲ │ ╱ │ 　│ 　│ 　│ ";
	gotoxy(boardx, boardy + 16);		cout << "│ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ │ ";
	gotoxy(boardx, boardy + 17);		cout << "│ 　│ 　│   │ ╱ │ ╲ │ 　│ 　│ 　│ ";
	gotoxy(boardx, boardy + 18);		cout << "╚ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╝ ";
}

void load_down_gotoxy(int no ,int max)
{
	COORD point;
	point.X = initialx; 
	point.Y = initialy + no * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//原位歸還
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		
	cout << " ChessBoard " << no + 1;
	point.X = initialx; 
	if (no == max)
		point.Y = initialy;
	else
		point.Y = initialy + no * 2 + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//到位反白
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	
	if (no == max)
		cout << " ChessBoard 1";
	else
		cout << " ChessBoard " << no + 2;
	gotoxy(117, 29);
}
void load_up_gotoxy(int no,int max)
{
	COORD pointup;
	pointup.X = initialx;  
	pointup.Y = initialy + no * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		
	cout << " ChessBoard " << no + 1;
	pointup.X = initialx;  
	if (no == 0)
		pointup.Y = initialy + max * 2;
	else
		pointup.Y = initialy + no * 2 - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	
	if (no == 0)
		cout << " ChessBoard " << max;
	else
		cout << " ChessBoard " << no;
	gotoxy(117, 29);
}

void initial_start()			//start game initial print
{
	const int row = 28, column = 117, left = 26, right = 72, boardleft = left + 8;
	/*外框*/
	gotoxy(0, 0);		cout << "┌";
	for (int i = 1; i < (column - 2); i++)		cout << "─";
	cout << "┐";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);					cout << "│";
		gotoxy(column - 2, i);		cout << "│";
	}
	gotoxy(0, row);		cout << "└";
	for (int i = 1; i < (column - 2); i++)		cout << "─";
	cout << "┘";
	/*左框框*/
	gotoxy(2, 1);		cout << "┌";
	for (int i = 1; i < left - 1; i++)		cout << "─";
	cout << "┐";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(2, i);				cout << "│";
		gotoxy(left + 1, i);	cout << "│";
	}
	gotoxy(2, row - 1);		cout << "└";
	for (int i = 1; i < left - 1; i++)		cout << "─";
	cout << "┘";
	/*右框框*/
	gotoxy(right, 16);		cout << "├";
	for (int i = right + 2; i < column - 3; i++)		cout << "─";
	cout << "┤";
	gotoxy(right, 1);		cout << "┌";
	for (int i = right; i < column - 5; i++)		cout << "─";
	cout << "┐";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(right, i);				cout << "│";
		gotoxy(column - 4, i);		cout << "│";
	}
	gotoxy(right, row - 1);		cout << "└";
	for (int i = right; i < column - 5; i++)		cout << "─";
	cout << "┘";
	/*寫字*/
	gotoxy(right + 10, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	cout << "現在輪到　";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*if (temp[90] == 1)
		cout << "紅色方";
	else
		cout << "黑色方";*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	cout << "          下棋";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(7, 1);		cout << "　戰　況　顯　示　";
	gotoxy(boardleft, 1);		cout << "１  ２  ３  ４  ５  ６　７　８　９";
	gotoxy(boardleft, row - 7);		cout << "九　八　七　六　五　四　三　二　一";			//---------------------(34,21)
	gotoxy(right + 9, 18);			cout << "Esc 選單";		gotoxy(right + 21, 18);		cout << "< 悔棋";	gotoxy(right + 31, 18);		cout << "> 還原";
	gotoxy(right + 8, 21);			cout << "Enter  選取棋子   q  取消選棋";
	gotoxy(right + 14, 23);		cout << "↑";
	gotoxy(right + 12, 24);			cout << "←";
	gotoxy(right + 16, 24);		cout << "→";
	gotoxy(right + 14, 25);		cout << "↓";
	gotoxy(right + 20, 24);		cout << "方向鍵控制游標"; 
	//------------------------------------------------------------------------------
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardleft, 2);			cout << "╔ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╗ ";
	gotoxy(boardleft, 3);			cout << "│ 　│ 　│   │ ╲ │ ╱ │ 　│ 　│ 　│ ";
	gotoxy(boardleft, 4);			cout << "│ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ │ ";
	gotoxy(boardleft, 5);			cout << "│ 　│ 　│   │ ╱ │ ╲ │ 　│ 　│ 　│ ";
	gotoxy(boardleft, 6);			cout << "│ ─ ╬ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ╬ ─ │ ";
	gotoxy(boardleft, 7);			cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardleft, 8);			cout << "│ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ │ ";
	gotoxy(boardleft, 9);			cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardleft, 10);		cout << "│ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ │ ";
	gotoxy(boardleft, 11);		cout << "│　　 　楚河　　　　　漢界　  　│ ";
	gotoxy(boardleft, 12);		cout << "│ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ │ ";
	gotoxy(boardleft, 13);		cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardleft, 14);		cout << "│ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ │ ";
	gotoxy(boardleft, 15);		cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardleft, 16);		cout << "│ ─ ╬ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ╬ ─ │ ";
	gotoxy(boardleft, 17);		cout << "│ 　│ 　│   │ ╲ │ ╱ │ 　│ 　│ 　│ ";
	gotoxy(boardleft, 18);		cout << "│ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ │ ";
	gotoxy(boardleft, 19);		cout << "│ 　│ 　│   │ ╱ │ ╲ │ 　│ 　│ 　│ ";
	gotoxy(boardleft, 20);		cout << "╚ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╧ ═ ╝ ";
	gotoxy(boardleft, row - 8);
}

void replay_left_gotoxy()
{
	COORD pointup;
	pointup.X = 94;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << "否(回主畫面)";
	pointup.X = 90;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 113);		cout << "是";
	gotoxy(92, 13);
}
void replay_right_gotoxy()
{
	COORD pointup;
	pointup.X = 90;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << "是";
	pointup.X = 94;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 113);		cout << "否(回主畫面)";
	gotoxy(106, 13);
}
void escmenu()
{
	gotoxy(32, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << "0繼續遊戲";
	gotoxy(46, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "1儲存檔案";
	gotoxy(60, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "2舉起白旗";
	gotoxy(32, 25);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "3偷看說明";
	gotoxy(46, 25);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "4可憐悔棋";
	gotoxy(60, 25);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "5離開遊戲";
	gotoxy(46, 27);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "←  →選擇";
	gotoxy(41, 23);
}
void esc_left_gotoxy(int num)
{
	COORD pointup;
	if (num > 2)
	{
		pointup.X = 32 + (num - 2) * 14;  pointup.Y = 25;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num + 1];
		pointup.X = 32 + (num - 3) * 14;  pointup.Y = 25;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
	}
	else
	{
		if (num == 2)
		{
			pointup.X = 32 + (num - 2) * 14;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num + 1];
			pointup.X = 32 + (num) * 14;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
		}
		else
		{
			pointup.X = 32 + (num + 1) * 14;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num + 1];
			pointup.X = 32 + (num) * 14;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
		}
	}
	gotoxy(117, 29);
}
void esc_right_gotoxy(int num)
{
	COORD pointup;
	if (num < 3)
	{
		pointup.X = 32 + (num - 1) * 14;  pointup.Y = 23;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num - 1];
		pointup.X = 32 + (num) * 14;  pointup.Y = 23;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
	}
	else
	{
		if (num == 3)
		{
			pointup.X = 60;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num - 1];
			pointup.X = 32;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
		}
		else
		{
			pointup.X = 32 + (num - 4) * 14;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num - 1];
			pointup.X = 32 + (num - 3) * 14;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
		}
	}
	gotoxy(117, 29);
}
void escclear()
{
	gotoxy(32, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	cout << "          ";
	gotoxy(46, 23);		cout << "         ";
	gotoxy(60, 23);		cout << "         ";
	gotoxy(32, 25);		cout << "         ";
	gotoxy(46, 25);		cout << "         ";
	gotoxy(60, 25);		cout << "         ";
	gotoxy(46, 27);		cout << "         ";
}
