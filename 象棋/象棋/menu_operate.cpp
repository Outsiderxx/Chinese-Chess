#include "menu_operate.h"
#define initialx 20
#define initialy	 5

const string word[15] = { "","�N","�h" ,"�H" ,"��" ,"��" ,"�]" ,"��" ,"��" ,"�K" ,"��" ,"��" ,"�X" ,"��" ,"�L" };
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
	/*�~��*/
	gotoxy(0, 0);		cout << "�z";
	for (int i = 1; i < column; i++)		cout << "�w";
	cout << "�{";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);		cout << "�x";
		gotoxy(column, i);		cout << "�x";
	}
	gotoxy(0, row);		cout << "�|";
	for (int i = 1; i < column; i++)		cout << "�w";
	cout << "�}";
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
	while (!enter_check)		//�ާ@����enter
	{
		key = _getch();
		switch (key)
		{
		case 13:					//read enter   
		{
			enter_check = true;	system("color 0f");		system("cls");		start();	 break;
		}
		case 72:			//read ��V�W  
		{
			no=no-2;
			if (no < 0){
				no = 0;	break;
			}
			else{
				load_up_gotoxy(no);	break;
			}
		}
		case 80:			//read ��V�U
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
	/*�~��*/
	gotoxy(0, 0);		cout << "�z";
	for (int i = 1; i < column; i++)		cout << "�w";
	cout << "�{";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);					cout << "�x";
		gotoxy(column, i);		cout << "�x";
	}
	gotoxy(0, row);		cout << "�|";
	for (int i = 1; i < column; i++)		cout << "�w";
	cout << "�}";
	/*���خ�*/
	gotoxy(2, 1);		cout << "�z";
	for (int i = 1; i < left - 1; i++)		cout << "�w";
	cout << "�{";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(2, i);				cout << "�x";
		gotoxy(left + 1, i);	cout << "�x";
	}
	gotoxy(2, row - 1);		cout << "�|";
	for (int i = 1; i < left - 1; i++)		cout << "�w";
	cout << "�}";
	/*�k�خ�*/
	gotoxy(right, 16);		cout << "�u";
	for (int i = right + 2; i < column - 1; i++)		cout << "�w";
	cout << "�t";
	gotoxy(right, 1);		cout << "�z";
	for (int i = right; i < column - 3; i++)		cout << "�w";
	cout << "�{";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(right, i);				cout << "�x";
		gotoxy(column - 2, i);		cout << "�x";
	}
	gotoxy(right, row - 1);		cout << "�|";
	for (int i = right; i < column - 3; i++)		cout << "�w";
	cout << "�}";
	/*�g�r*/
	gotoxy(right + 12, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	cout << "�{�b����@";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*if (temp[90] == 1)
		cout << "�����";
	else
		cout << "�¦��";*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	cout << "      �U��";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(7, 1);		cout << "�@�ԡ@�p�@��@�ܡ@";
	gotoxy(boardleft, 1);		cout << "��  ��  ��  ��  ��  ���@���@���@��";
	gotoxy(boardleft, row - 7);		cout << "�E�@�K�@�C�@���@���@�|�@�T�@�G�@�@";
	gotoxy(right + 9, 18);			cout << "Esc ���";
	gotoxy(right + 21, 18);		cout << "< ����";
	gotoxy(right + 31, 18);		cout << "> �٭�";
	gotoxy(right + 13, 21);			cout << "Enter     ����Ѥl";
	gotoxy(right + 14, 23);		cout << "��";
	gotoxy(right + 12, 24);			cout << "��";
	gotoxy(right + 16, 24);		cout << "��";
	gotoxy(right + 14, 25);		cout << "��";
	gotoxy(right + 20, 24);		cout << "��V�䱱����";
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << fileword[((no-2)/2)];
	point.X = initialx; point.Y = initialy + no;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << fileword[(no/2)];
	gotoxy(initialx + 99, initialy + 24);
}
void load_up_gotoxy(int no)
{
	COORD pointup;
	pointup.X = initialx;  pointup.Y = initialy + no + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << fileword[((no+2)/2)];
	pointup.X = initialx;  pointup.Y = initialy + no;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << fileword[(no/2)];
	gotoxy(initialx + 99, initialy + 24);
}
void board_basic(int boardx,int boardy)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardx, boardy);				cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ";
	gotoxy(boardx, boardy+1);			cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardx, boardy + 2);		cout << "�x �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w �x ";
	gotoxy(boardx, boardy + 3);		cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardx, boardy + 4);		cout << "�x �w �� �w �q �w �q �w �q �w �q �w �q �w �� �w �x ";
	gotoxy(boardx, boardy + 5);		cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardx, boardy + 6);		cout << "�x �w �q �w �� �w �q �w �� �w �q �w �� �w �q �w �x ";
	gotoxy(boardx, boardy + 7);		cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardx, boardy + 8);		cout << "�x �w �r �w �r �w �r �w �r �w �r �w �r �w �r �w �x ";
	gotoxy(boardx, boardy + 9);		cout << "�x�@�@ �@���e�@�@�@�@�@�~�ɡ@  �@�x ";
	gotoxy(boardx, boardy + 10);		cout << "�x �w �s �w �s �w �s �w �s �w �s �w �s �w �s �w �x ";
	gotoxy(boardx, boardy + 11);		cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardx, boardy + 12);		cout << "�x �w �q �w �� �w �q �w �� �w �q �w �� �w �q �w �x ";
	gotoxy(boardx, boardy + 13);		cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardx, boardy + 14);		cout << "�x �w �� �w �q �w �q �w �q �w �q �w �q �w �� �w �x ";
	gotoxy(boardx, boardy + 15);		cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardx, boardy + 16);		cout << "�x �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w �x ";
	gotoxy(boardx, boardy + 17);		cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardx, boardy + 18);		cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ";
}
//void check_enter()
//{
//	char key;		int opa;
//	bool enter_check = 0;
//	while (!enter_check)		//�ާ@����enter
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
