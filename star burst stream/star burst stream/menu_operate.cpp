#include "menu_operate.h"
#define initialx 20
#define initialy	 5

const string fileword[10] = { " File 1 : "," File 2 : "," File 3 : "," File 4 : "," File 5 : "," File 6 : "," File 7 : "," File 8 : "," File 9 : "," File 10 : " };

void load()						//file list
{
	const int row = 28, column = 117;
	/*¥~®Ø*/
	gotoxy(0, 0);		cout << "¢z";
	for (int i = 1; i < column; i++)		cout << "¢w";
	cout << "¢{";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);		cout << "¢x";
		gotoxy(column, i);		cout << "¢x";
	}
	gotoxy(0, row);		cout << "¢|";
	for (int i = 1; i < column; i++)		cout << "¢w";
	cout << "¢}";
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
	while (!enter_check)		//¾Þ§@ª½¨ìenter
	{
		key = _getch();
		switch (key)
		{
		case 13:					//read enter   
		{
			enter_check = true;	system("color 0f");		system("cls");		 break;
		}
		case 72:			//read ¤è¦V¤W  
		{
			no = no - 2;
			if (no < 0) {
				no = 0;	break;
			}
			else {
				load_up_gotoxy(no);	break;
			}
		}
		case 80:			//read ¤è¦V¤U
		{
			no = no + 2;
			if (no > 18) {
				no = 18;		break;
			}
			else {
				load_down_gotoxy(no);	break;
			}
		}
		}
	}
}
void caption()				//rules,setting,others
{
	fstream file;
	file.open("manual.txt", ios::in | ios::binary);
	if (file.is_open())
	{
		string str;
		while (!file.eof())					//	print rules (30 rows a page)
		{
			for (int i = 0; i < 30 && getline(file, str); i++)	cout << str << endl;
			system("pause");
			system("cls");
		}
	}
	else
		cout << "error!!" << endl;		//exit(0);
}
//-----------------------------------------------------------------other assistance function------------
void initial_start()			//start game initial print
{
	const int row = 28, column = 117, left = 26, right = 72, boardleft = left + 8;
	/*¥~®Ø*/
	gotoxy(0, 0);		cout << "¢z";
	for (int i = 1; i < (column-2); i++)		cout << "¢w";
	cout << "¢{";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);					cout << "¢x";
		gotoxy(column-2, i);		cout << "¢x";
	}
	gotoxy(0, row);		cout << "¢|";
	for (int i = 1; i < (column-2); i++)		cout << "¢w";
	cout << "¢}";
	/*¥ª®Ø®Ø*/
	gotoxy(2, 1);		cout << "¢z";
	for (int i = 1; i < left - 1; i++)		cout << "¢w";
	cout << "¢{";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(2, i);				cout << "¢x";
		gotoxy(left + 1, i);	cout << "¢x";
	}
	gotoxy(2, row - 1);		cout << "¢|";
	for (int i = 1; i < left - 1; i++)		cout << "¢w";
	cout << "¢}";
	/*¥k®Ø®Ø*/
	gotoxy(right, 16);		cout << "¢u";
	for (int i = right + 2; i < column - 3; i++)		cout << "¢w";
	cout << "¢t";
	gotoxy(right, 1);		cout << "¢z";
	for (int i = right; i < column - 5; i++)		cout << "¢w";
	cout << "¢{";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(right, i);				cout << "¢x";
		gotoxy(column - 4, i);		cout << "¢x";
	}
	gotoxy(right, row - 1);		cout << "¢|";
	for (int i = right; i < column - 5; i++)		cout << "¢w";
	cout << "¢}";
	/*¼g¦r*/
	gotoxy(right + 10, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	cout << "²{¦b½ü¨ì¡@";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*if (temp[90] == 1)
		cout << "¬õ¦â¤è";
	else
		cout << "¶Â¦â¤è";*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	cout << "          ¤U´Ñ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(7, 1);		cout << "¡@¾Ô¡@ªp¡@Åã¡@¥Ü¡@";
	gotoxy(boardleft, 1);		cout << "¢°  ¢±  ¢²  ¢³  ¢´  ¢µ¡@¢¶¡@¢·¡@¢¸";
	gotoxy(boardleft, row - 7);		cout << "¤E¡@¤K¡@¤C¡@¤»¡@¤­¡@¥|¡@¤T¡@¤G¡@¤@";
	gotoxy(right + 9, 18);			cout << "Esc ¿ï³æ";
	gotoxy(right + 21, 18);		cout << "< ®¬´Ñ";
	gotoxy(right + 31, 18);		cout << "> ÁÙ­ì";
	gotoxy(right + 13, 21);			cout << "Enter     ¿ï¨ú´Ñ¤l";
	gotoxy(right + 14, 23);		cout << "¡ô";
	gotoxy(right + 12, 24);			cout << "¡ö";
	gotoxy(right + 16, 24);		cout << "¡÷";
	gotoxy(right + 14, 25);		cout << "¡õ";
	gotoxy(right + 20, 24);		cout << "¤è¦VÁä±±¨î´å¼Ð";
	//------------------------------------------------------------------------------
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardleft, 2);			cout << "ùÝ ùù ùç ùù ùç ùù ùç ùù ùç ùù ùç ùù ùç ùù ùç ùù ùß ";
	gotoxy(boardleft, 3);			cout << "¢x ¡@¢x ¡@¢x   ¢x ¢­ ¢x ¢¬ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardleft, 4);			cout << "¢x ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢x ";
	gotoxy(boardleft, 5);			cout << "¢x ¡@¢x ¡@¢x   ¢x ¢¬ ¢x ¢­ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardleft, 6);			cout << "¢x ¢w ùá ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ùá ¢w ¢x ";
	gotoxy(boardleft, 7);			cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardleft, 8);			cout << "¢x ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ¢x ";
	gotoxy(boardleft, 9);			cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardleft, 10);		cout << "¢x ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢x ";
	gotoxy(boardleft, 11);		cout << "¢x¡@¡@ ¡@·¡ªe¡@¡@¡@¡@¡@º~¬É¡@  ¡@¢x ";
	gotoxy(boardleft, 12);		cout << "¢x ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢x ";
	gotoxy(boardleft, 13);		cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardleft, 14);		cout << "¢x ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ¢x ";
	gotoxy(boardleft, 15);		cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardleft, 16);		cout << "¢x ¢w ùá ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ùá ¢w ¢x ";
	gotoxy(boardleft, 17);		cout << "¢x ¡@¢x ¡@¢x   ¢x ¢­ ¢x ¢¬ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardleft, 18);		cout << "¢x ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢x ";
	gotoxy(boardleft, 19);		cout << "¢x ¡@¢x ¡@¢x   ¢x ¢¬ ¢x ¢­ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardleft, 20);		cout << "ùã ùù ùí ùù ùí ùù ùí ùù ùí ùù ùí ùù ùí ùù ùí ùù ùå ";
	gotoxy(boardleft, row - 8);
}
void load_down_gotoxy(int no)
{
	COORD point;
	point.X = initialx; point.Y = initialy + no - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//­ì¦ìÂkÁÙ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << fileword[((no - 2) / 2)];
	point.X = initialx; point.Y = initialy + no;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//¨ì¦ì¤Ï¥Õ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << fileword[(no / 2)];
	gotoxy(initialx + 99, initialy + 24);
}
void load_up_gotoxy(int no)
{
	COORD pointup;
	pointup.X = initialx;  pointup.Y = initialy + no + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//­ì¦ìÂkÁÙ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << fileword[((no + 2) / 2)];
	pointup.X = initialx;  pointup.Y = initialy + no;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//¨ì¦ì¤Ï¥Õ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << fileword[(no / 2)];
	gotoxy(initialx + 99, initialy + 24);
}
void board_basic(int boardx, int boardy)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardx, boardy);				cout << "ùÝ ùù ùç ùù ùç ùù ùç ùù ùç ùù ùç ùù ùç ùù ùç ùù ùß ";
	gotoxy(boardx, boardy + 1);			cout << "¢x ¡@¢x ¡@¢x   ¢x ¢­ ¢x ¢¬ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardx, boardy + 2);		cout << "¢x ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢x ";
	gotoxy(boardx, boardy + 3);		cout << "¢x ¡@¢x ¡@¢x   ¢x ¢¬ ¢x ¢­ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardx, boardy + 4);		cout << "¢x ¢w ùá ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ùá ¢w ¢x ";
	gotoxy(boardx, boardy + 5);		cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardx, boardy + 6);		cout << "¢x ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ¢x ";
	gotoxy(boardx, boardy + 7);		cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardx, boardy + 8);		cout << "¢x ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢x ";
	gotoxy(boardx, boardy + 9);		cout << "¢x¡@¡@ ¡@·¡ªe¡@¡@¡@¡@¡@º~¬É¡@  ¡@¢x ";
	gotoxy(boardx, boardy + 10);		cout << "¢x ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢x ";
	gotoxy(boardx, boardy + 11);		cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardx, boardy + 12);		cout << "¢x ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ùá ¢w ¢q ¢w ¢x ";
	gotoxy(boardx, boardy + 13);		cout << "¢x ¡@¢x¡@ ¢x¡@ ¢x¡@ ¢x¡@ ¢x ¡@¢x ¡@¢x¡@ ¢x ";
	gotoxy(boardx, boardy + 14);		cout << "¢x ¢w ùá ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ùá ¢w ¢x ";
	gotoxy(boardx, boardy + 15);		cout << "¢x ¡@¢x ¡@¢x   ¢x ¢­ ¢x ¢¬ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardx, boardy + 16);		cout << "¢x ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢x ";
	gotoxy(boardx, boardy + 17);		cout << "¢x ¡@¢x ¡@¢x   ¢x ¢¬ ¢x ¢­ ¢x ¡@¢x ¡@¢x ¡@¢x ";
	gotoxy(boardx, boardy + 18);		cout << "ùã ùù ùí ùù ùí ùù ùí ùù ùí ùù ùí ùù ùí ùù ùí ùù ùå ";
}
