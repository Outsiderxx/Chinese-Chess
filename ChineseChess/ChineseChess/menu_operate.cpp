#include "menu_operate.h"
#define initialx 17
#define initialy	 5

const string word[15] = { "","�N","�h" ,"�H" ,"��" ,"��" ,"�]" ,"��" ,"��" ,"�K" ,"��" ,"��" ,"�X" ,"��" ,"�L" };
const string ChessBoardword[10] = { " ChessBoard 1 : "," ChessBoard 2 : "," ChessBoard 3 : "," ChessBoard 4 : "," ChessBoard 5 : "," ChessBoard 6 : "," ChessBoard 7 : "," ChessBoard 8 : "," ChessBoard 9 : "," ChessBoard 10 : " };
const string escwords[6] = { "0�~��C��","1�x�s�ɮ�","2�|�_�պX","3���ݻ���","4�i������","5���}�C��" };

void load(int boardNum)						//ChessBoard list
{
	const int row = 28, column = 117;
	/*�~��*/
	gotoxy(0, 0);
	cout << "�z";
	for (int i = 1; i < column; i++)
		cout << "�w";
	cout << "�{";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);
		cout << "�x";
		gotoxy(column, i);
		cout << "�x";
	}
	gotoxy(0, row);
	cout << "�|";
	for (int i = 1; i < column; i++)
		cout << "�w";
	cout << "�}";
	gotoxy(10, 2);
	cout << "------Select your record------";
	gotoxy(47, 2);
	cout << "------Chessboard Preview------";
	gotoxy(85, 5);
	cout << "Press ���� ��ܭn�w�����ѽL";
	gotoxy(85, 8);
	cout << "Press Enter �w���ѽL/�i�J�C��";
	gotoxy(85, 11);
	cout << "Press 'q' ��ܨ�L�ѽL";
	gotoxy(85, 14);
	cout << "Press Esc �^��D�e��";
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
	gotoxy(boardx, boardy);				cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ";
	gotoxy(boardx, boardy + 1);			cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardx, boardy + 2);			cout << "�x �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w �x ";
	gotoxy(boardx, boardy + 3);			cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardx, boardy + 4);			cout << "�x �w �� �w �q �w �q �w �q �w �q �w �q �w �� �w �x ";
	gotoxy(boardx, boardy + 5);			cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardx, boardy + 6);			cout << "�x �w �q �w �� �w �q �w �� �w �q �w �� �w �q �w �x ";
	gotoxy(boardx, boardy + 7);			cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardx, boardy + 8);			cout << "�x �w �r �w �r �w �r �w �r �w �r �w �r �w �r �w �x ";
	gotoxy(boardx, boardy + 9);			cout << "�x�@�@ �@���e�@�@�@�@�@�~�ɡ@  �@�x ";
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

void load_down_gotoxy(int no ,int max)
{
	COORD point;
	point.X = initialx; 
	point.Y = initialy + no * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		
	cout << " ChessBoard " << no + 1;
	point.X = initialx; 
	if (no == max)
		point.Y = initialy;
	else
		point.Y = initialy + no * 2 + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//���ϥ�
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		
	cout << " ChessBoard " << no + 1;
	pointup.X = initialx;  
	if (no == 0)
		pointup.Y = initialy + max * 2;
	else
		pointup.Y = initialy + no * 2 - 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
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
	/*�~��*/
	gotoxy(0, 0);		cout << "�z";
	for (int i = 1; i < (column - 2); i++)		cout << "�w";
	cout << "�{";
	for (int i = 1; i < row; i++)
	{
		gotoxy(0, i);					cout << "�x";
		gotoxy(column - 2, i);		cout << "�x";
	}
	gotoxy(0, row);		cout << "�|";
	for (int i = 1; i < (column - 2); i++)		cout << "�w";
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
	for (int i = right + 2; i < column - 3; i++)		cout << "�w";
	cout << "�t";
	gotoxy(right, 1);		cout << "�z";
	for (int i = right; i < column - 5; i++)		cout << "�w";
	cout << "�{";
	for (int i = 2; i < row - 1; i++)
	{
		gotoxy(right, i);				cout << "�x";
		gotoxy(column - 4, i);		cout << "�x";
	}
	gotoxy(right, row - 1);		cout << "�|";
	for (int i = right; i < column - 5; i++)		cout << "�w";
	cout << "�}";
	/*�g�r*/
	gotoxy(right + 10, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	cout << "�{�b����@";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*if (temp[90] == 1)
		cout << "�����";
	else
		cout << "�¦��";*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);	cout << "          �U��";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(7, 1);		cout << "�@�ԡ@�p�@��@�ܡ@";
	gotoxy(boardleft, 1);		cout << "��  ��  ��  ��  ��  ���@���@���@��";
	gotoxy(boardleft, row - 7);		cout << "�E�@�K�@�C�@���@���@�|�@�T�@�G�@�@";			//---------------------(34,21)
	gotoxy(right + 9, 18);			cout << "Esc ���";		gotoxy(right + 21, 18);		cout << "< ����";	gotoxy(right + 31, 18);		cout << "> �٭�";
	gotoxy(right + 8, 21);			cout << "Enter  ����Ѥl   q  �������";
	gotoxy(right + 14, 23);		cout << "��";
	gotoxy(right + 12, 24);			cout << "��";
	gotoxy(right + 16, 24);		cout << "��";
	gotoxy(right + 14, 25);		cout << "��";
	gotoxy(right + 20, 24);		cout << "��V�䱱����"; 
	//------------------------------------------------------------------------------
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	gotoxy(boardleft, 2);			cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ";
	gotoxy(boardleft, 3);			cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardleft, 4);			cout << "�x �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w �x ";
	gotoxy(boardleft, 5);			cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardleft, 6);			cout << "�x �w �� �w �q �w �q �w �q �w �q �w �q �w �� �w �x ";
	gotoxy(boardleft, 7);			cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardleft, 8);			cout << "�x �w �q �w �� �w �q �w �� �w �q �w �� �w �q �w �x ";
	gotoxy(boardleft, 9);			cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardleft, 10);		cout << "�x �w �r �w �r �w �r �w �r �w �r �w �r �w �r �w �x ";
	gotoxy(boardleft, 11);		cout << "�x�@�@ �@���e�@�@�@�@�@�~�ɡ@  �@�x ";
	gotoxy(boardleft, 12);		cout << "�x �w �s �w �s �w �s �w �s �w �s �w �s �w �s �w �x ";
	gotoxy(boardleft, 13);		cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardleft, 14);		cout << "�x �w �q �w �� �w �q �w �� �w �q �w �� �w �q �w �x ";
	gotoxy(boardleft, 15);		cout << "�x �@�x�@ �x�@ �x�@ �x�@ �x �@�x �@�x�@ �x ";
	gotoxy(boardleft, 16);		cout << "�x �w �� �w �q �w �q �w �q �w �q �w �q �w �� �w �x ";
	gotoxy(boardleft, 17);		cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardleft, 18);		cout << "�x �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w �x ";
	gotoxy(boardleft, 19);		cout << "�x �@�x �@�x   �x �� �x �� �x �@�x �@�x �@�x ";
	gotoxy(boardleft, 20);		cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ";
	gotoxy(boardleft, row - 8);
}

void replay_left_gotoxy()
{
	COORD pointup;
	pointup.X = 94;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << "�_(�^�D�e��)";
	pointup.X = 90;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 113);		cout << "�O";
	gotoxy(92, 13);
}
void replay_right_gotoxy()
{
	COORD pointup;
	pointup.X = 90;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << "�O";
	pointup.X = 94;  pointup.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 113);		cout << "�_(�^�D�e��)";
	gotoxy(106, 13);
}
void escmenu()
{
	gotoxy(32, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << "0�~��C��";
	gotoxy(46, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "1�x�s�ɮ�";
	gotoxy(60, 23);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "2�|�_�պX";
	gotoxy(32, 25);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "3���ݻ���";
	gotoxy(46, 25);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "4�i������";
	gotoxy(60, 25);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "5���}�C��";
	gotoxy(46, 27);		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			cout << "��  �����";
	gotoxy(41, 23);
}
void esc_left_gotoxy(int num)
{
	COORD pointup;
	if (num > 2)
	{
		pointup.X = 32 + (num - 2) * 14;  pointup.Y = 25;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num + 1];
		pointup.X = 32 + (num - 3) * 14;  pointup.Y = 25;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
	}
	else
	{
		if (num == 2)
		{
			pointup.X = 32 + (num - 2) * 14;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num + 1];
			pointup.X = 32 + (num) * 14;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
		}
		else
		{
			pointup.X = 32 + (num + 1) * 14;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num + 1];
			pointup.X = 32 + (num) * 14;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
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
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num - 1];
		pointup.X = 32 + (num) * 14;  pointup.Y = 23;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
	}
	else
	{
		if (num == 3)
		{
			pointup.X = 60;  pointup.Y = 23;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num - 1];
			pointup.X = 32;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << escwords[num];
		}
		else
		{
			pointup.X = 32 + (num - 4) * 14;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << escwords[num - 1];
			pointup.X = 32 + (num - 3) * 14;  pointup.Y = 25;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
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
