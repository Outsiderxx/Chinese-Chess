#include "start_menu.h"
#define initialx 54.5
#define initialy 21
const string menu[4] = { "�}�l�C��", "Ū���ɮ�" ,"�ާ@����" ,"  ���}  " };			//���const����

void gotoxy(int x, int y)	
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void menuprint()			
{
	system("mode con cols=120 lines=30");			//set console size
	for (int i = 0; i < 19; i++)	{	gotoxy(8, 0 + i);	cout << "|";	}
	for (int i = 0; i < 19; i++)	{	gotoxy(110, 0 + i);	cout << "|";	}
	system("color 0e");
	gotoxy(0, 5);
	cout << "\t\t";	cout << " 	   �� 	       ������������������������������" << "\t      ������������������" << "\t          �� " << "     ��   ��           " << endl;
	cout << "\t\t"; cout << "	   �� 	       �� ���������������������� ��" << "\t          ��" << "\t          �� " << "     ��   ��   " << endl;
	cout << "\t\t"; cout << "    ������������������������������    ��      ��      ��" << "\t          ��" << "\t        ����������" << "   �������������� " << endl;
	cout << "\t\t"; cout << "    ��	   ��      ��    ��      ��      ��" << "\t          ��" << "\t          ��      " << "��   �� " << endl;
	cout << "\t\t"; cout << "    ��	   ��      ��    ��      ��      ��" << "\t\t\t         /�� \\" << "    ����������  " << endl;
	cout << "\t\t"; cout << "    ��	   ��      ��    �� ���������������������� ��" << "\t      ������������������" << "\t        / ��  \\" << "   ��   ��  " << endl;
	cout << "\t\t"; cout << "    ��	   ��      ��    ��      ��      �� " << "\t\t         ��" << "     /  ��   \\" << "  ����������   " << endl;
	cout << "\t\t"; cout << "    ������������������������������    ��      �� �B   ��" << "\t      ������������������" << "\t      /   ��    \\" << " ��   ��" << endl;
	cout << "\t\t"; cout << "	   ��	       ��      ��  �B  ��" << "\t         ����" << "\t          ��     " << "��������������      " << endl;
	cout << "\t\t"; cout << "	   ��	       �� ���������������������� ��" << "\t       ��  ��" << "\t          �� " << "     //  \\\\   " << endl;
	cout << "\t\t"; cout << "	   ��	       ������������������������������" << "\t     ��    ����������" << "\t          �� " << "    //    \\\\    " << endl;
	gotoxy(0, initialy - 3);	cout << "------------------------------------------------------------------------------------------------------------------------";
	gotoxy(initialx, initialy);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	cout << menu[0];
	gotoxy(initialx, initialy + 1);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	cout << menu[1];
	gotoxy(initialx, initialy + 2); cout << menu[2];
	gotoxy(initialx, initialy + 3);	cout << menu[3];
	gotoxy(initialx + 64.5, initialy + 8);
}
void up_gotoxy(int num)		
{
	COORD pointup;
	pointup.X = initialx;  pointup.Y = initialy + num + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << menu[num + 1];
	pointup.X = initialx;  pointup.Y = initialy + num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << menu[num];
	gotoxy(initialx + 64.5, initialy + 8);
}
void down_gotoxy(int num)		
{
	COORD point;
	point.X = initialx; point.Y = initialy + num - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << menu[num - 1];
	point.X = initialx; point.Y = initialy + num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << menu[num];
	gotoxy(initialx + 64.5, initialy + 8);
}
int menu_control()		//��汱��
{
	char key;	int no = 0;		bool enter_check = 0;
	while (!enter_check)		//�ާ@����enter
	{
		key = _getch();
		switch (key)
		{
		case 13:					//read enter   
		{
			enter_check = true;
			system("color 0f");
			system("cls");
			break;
		}
		case 72:			//read ��V�W  
		{
			no--;
			if (no < 0)
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
			if (no > 3)
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
	return no;
}
