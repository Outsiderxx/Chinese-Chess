#include<iostream>
#include <windows.h>
#include<string>
#include <conio.h>
#include <functional>			//function pointer

#define initialx 50
#define initialy 20
using namespace std;

const string menu[4] = { "�}�l�C��", "Ū���ɮ�" ,"�ާ@����" ," ���} " };			//���const����

void menuprint()
{
	cout << " 	  �� 	     ����������������������" << endl;
	cout << "	  �� 	     �� �������������� ��" << endl;
	cout << "     ����������������������     ��    ��    ��" << endl;
	cout << "     ��	  ��    ��     ��    ��    ��" << endl;
	cout << "     ��	  ��    ��     ��    ��    ��" << endl;
	cout << "     ��	  ��    ��     �� �������������� ��" << endl;
	cout << "     ��	  ��    ��     ��	  ��    �� " << endl;
	cout << "     ����������������������     ��	  ���B  ��" << endl;
	cout << "	  ��	     ��	  �� �B ��" << endl;
	cout << "	  ��	     �� �������������� ��" << endl;
	cout << "	  ��	     ����������������������" << endl;
}
void gotoxy(int x,int y)	//initial execute
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void up_gotoxy(int num)		//up execute
{
	COORD pointup;
	pointup.X = initialx;  pointup.Y = initialy+num + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << menu[num + 1];
	pointup.X = initialx;  pointup.Y = initialy+num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << menu[num];

}
void down_gotoxy(int num)		//down execute
{
	COORD point;
	point.X = initialx; point.Y = initialy+num - 1;		
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << menu[num - 1];
	point.X = initialx; point.Y = initialy+num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << menu[num];
}
int main()
{
	char key;
	int no = 0;	
	menuprint();
	gotoxy(initialx,initialy);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	cout << menu[0];
	gotoxy(initialx, initialy+1);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	cout << menu[1];
	gotoxy(initialx, initialy+2); cout << menu[2];
	gotoxy(initialx, initialy+3);	cout << menu[3];
	while (1)
	{
		key = _getch();
		switch (key)
		{	
		case 13:					//read enter   execute   function<type( args )> menuFunction[] = { a ,b , c };
		{
			system("Cls");
			cout << no;
				break;
		}
		case 72:			//read ��V�W  
		{
			no--;
			if (no<0)
			{
				no = 0;
				break;
			}
			else
			{
				up_gotoxy(no);
				break;
			}
		}
		case 80:			//read ��V�U
		{
			no++;
			if (no>3)
			{
				no = 3;
				break;
			}
			else
			{
				down_gotoxy(no);
				break;
			}
		}
		}
	}
	return 0;
}