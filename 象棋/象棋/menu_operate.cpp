#include "menu_operate.h"
#define initialx 20
#define initialy	 5

const string word[15] = { "","將","士" ,"象" ,"車" ,"馬" ,"包" ,"卒" ,"帥" ,"仕" ,"相" ,"車" ,"傌" ,"炮" ,"兵" };
const string fileword[10] = { " File 1 : "," File 2 : "," File 3 : "," File 4 : "," File 5 : "," File 6 : "," File 7 : "," File 8 : "," File 9 : "," File 10 : " };
function<void()> menuFunction[] = { start ,load ,caption,end };

//----------------------------------------------------------op1---------------------------------------------
void start()					//start game
{
	initial_start();
	while (_kbhit())
	{
		//do something
	}
}
//-----------------------------------------------------------op2-----------------------------------------
void load()						//file list
{
	const int row = 28, column = 117;
	/*外框*/
	gotoxy(0, 0);		cout << "┌";
	for (int i = 1; i < column; i++)		cout << "─";
	cout << "┐";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);		cout << "│";
		gotoxy(column, i);		cout << "│";
	}
	gotoxy(0, row);		cout << "└";
	for (int i = 1; i < column; i++)		cout << "─";
	cout << "┘";
	//--------------------------------------------------
	gotoxy(35, 2);	cout << "---------------Select your record---------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	gotoxy(20, 5);	cout << " File 1 : ";	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); gotoxy(20, 7);	cout << " File 2 : ";
	gotoxy(20, 9);	cout << " File 3 : ";	gotoxy(20, 11);	cout << " File 4 : ";
	gotoxy(20, 13);	cout << " File 5 : ";	gotoxy(20, 15);	cout << " File 6 : ";
	gotoxy(20, 17);	cout << " File 7 : ";	gotoxy(20, 19);	cout << " File 8 : ";
	gotoxy(20, 21);	cout << " File 9 : ";	gotoxy(20, 23);	cout << " File 10 : ";
	board_basic(55, 5);
	gotoxy(initialx + 99, initialy + 24);
	char key;	int no = 0;		bool enter_check = 0;
	while (!enter_check)		//操作直到enter
	{
		key = _getch();
		switch (key)
		{
		case 13:					//read enter   
		{
			enter_check = true;	system("color 0f");		system("cls");		start();	 break;
		}
		case 72:			//read 方向上  
		{
			no=no-2;
			if (no < 0){
				no = 0;	break;
			}
			else{
				load_up_gotoxy(no);	break;
			}
		}
		case 80:			//read 方向下
		{
			no=no+2;
			if (no > 18){
				no = 18;		break;
			}
			else{
				load_down_gotoxy(no);	break;
			}
		}
		}
	}
}
//------------------------------------------------------------op3----------------------------------------
void caption()				//rules,setting,others
{
	fstream file;
	file.open("caption.txt", ios::in | ios::binary);
	if(file.is_open())
	{
		string str;
		while (!file.eof())					//	print rules (30 rows a page)
		{
			for (int i = 0; i < 30 && getline(file, str); i++)	cout << str << endl;
			system("pause");
			system("cls");
		}
		char key;		int opa;
		bool enter_check = 0;
		menuprint();
		opa = menu_control();			//get select from user
		menuFunction[opa]();
	}
	else
		cout << "error!!"<< endl;		//exit(0);
}
//----------------------------------------------------------------op4-----------------------------------
void end()
{
	exit(0);
}
//-----------------------------------------------------------------other assistance function------------
void initial_start()			//start game initial print
{
	const int row = 28, column = 117, left = 26, right = 72, boardleft = left + 8;
	/*外框*/
	gotoxy(0, 0);		cout << "┌";
	for (int i = 1; i < column; i++)		cout << "─";
	cout << "┐";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);					cout << "│";
		gotoxy(column, i);		cout << "│";
	}
	gotoxy(0, row);		cout << "└";
	for (int i = 1; i < column; i++)		cout << "─";
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
	for (int i = right + 2; i < column - 1; i++)		cout << "─";
	cout << "┤";
	gotoxy(right, 1);		cout << "┌";
	for (int i = right; i < column - 3; i++)		cout << "─";
	cout << "┐";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(right, i);				cout << "│";
		gotoxy(column - 2, i);		cout << "│";
	}
	gotoxy(right, row - 1);		cout << "└";
	for (int i = right; i < column - 3; i++)		cout << "─";
	cout << "┘";
	/*寫字*/
	gotoxy(right + 12, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	cout << "現在輪到　";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*if (temp[90] == 1)
		cout << "紅色方";
	else
		cout << "黑色方";*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	cout << "      下棋";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(7, 1);		cout << "　戰　況　顯　示　";
	gotoxy(boardleft, 1);		cout << "１  ２  ３  ４  ５  ６　７　８　９";
	gotoxy(boardleft, row - 7);		cout << "九　八　七　六　五　四　三　二　一";
	gotoxy(right + 9, 18);			cout << "Esc 選單";
	gotoxy(right + 21, 18);		cout << "< 悔棋";
	gotoxy(right + 31, 18);		cout << "> 還原";
	gotoxy(right + 13, 21);			cout << "Enter     選取棋子";
	gotoxy(right + 14, 23);		cout << "↑";
	gotoxy(right + 12, 24);			cout << "←";
	gotoxy(right + 16, 24);		cout << "→";
	gotoxy(right + 14, 25);		cout << "↓";
	gotoxy(right + 20, 24);		cout << "方向鍵控制游標";
	//------------------------------------------------------------------------------
	board_basic(boardleft, 2);
	gotoxy(boardleft, row - 8);
	fstream file;
	file.open("initial.txt");
	if (file.is_open())
	{
		string str;
		while (getline(file, str))
		{
			//cout << str;
		}
	}
}
void load_down_gotoxy(int no)
{
	COORD point;
	point.X = initialx; point.Y = initialy + no - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//原位歸還
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << fileword[((no-2)/2)];
	point.X = initialx; point.Y = initialy + no;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//到位反白
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << fileword[(no/2)];
	gotoxy(initialx + 99, initialy + 24);
}
void load_up_gotoxy(int no)
{
	COORD pointup;
	pointup.X = initialx;  pointup.Y = initialy + no + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//原位歸還
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << fileword[((no+2)/2)];
	pointup.X = initialx;  pointup.Y = initialy + no;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//到位反白
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << fileword[(no/2)];
	gotoxy(initialx + 99, initialy + 24);
}
void board_basic(int boardx,int boardy)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardx, boardy);				cout << "╔ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╤ ═ ╗ ";
	gotoxy(boardx, boardy+1);			cout << "│ 　│ 　│   │ ╲ │ ╱ │ 　│ 　│ 　│ ";
	gotoxy(boardx, boardy + 2);		cout << "│ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ │ ";
	gotoxy(boardx, boardy + 3);		cout << "│ 　│ 　│   │ ╱ │ ╲ │ 　│ 　│ 　│ ";
	gotoxy(boardx, boardy + 4);		cout << "│ ─ ╬ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ╬ ─ │ ";
	gotoxy(boardx, boardy + 5);		cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardx, boardy + 6);		cout << "│ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ ╬ ─ ┼ ─ │ ";
	gotoxy(boardx, boardy + 7);		cout << "│ 　│　 │　 │　 │　 │ 　│ 　│　 │ ";
	gotoxy(boardx, boardy + 8);		cout << "│ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ │ ";
	gotoxy(boardx, boardy + 9);		cout << "│　　 　楚河　　　　　漢界　  　│ ";
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
//void check_enter()
//{
//	char key;		int opa;
//	bool enter_check = 0;
//	while (!enter_check)		//操作直到enter
//	{
//		key = _getch();
//		if (key == 13)
//		{
//			enter_check = true;
//			system("color 0f");
//			system("cls");
//			menuprint();
//			opa = menu_control();			//get select from user
//			menuFunction[opa]();
//		}
//	}
//}
