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
	system("mode con cols=118 lines=30");			//set console size
	for (int i = 0; i < 19; i++) { gotoxy(8, 0 + i);	cout << "|"; }
	for (int i = 0; i < 19; i++) { gotoxy(110, 0 + i);	cout << "|"; }
	system("color 0e");
	gotoxy(20, 2); cout << "[1;36;44m�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� [m" << '\n';
	gotoxy(20, 3); cout << "[1;36;44m�� [37;40m[33;50m�~ �w �w �w �w �w �w �w �w �w �w  [37m  �� �N�� �h�� �H�� ���� ���� �]�� �� ��       [36;44m�� [m" << '\n';
	gotoxy(20, 4); cout << "[1;36;44m�� [33;40m�x Do it Again !!!!�x   [37m  <[33m��[37m��<[36m��[37m��<[32m��[37m��<[31m��[37m��<[36m��[37m��<[32m��[37m��<[33m��[37m��<[31m��[37m��<[35m��[37m��     [36;44m�� [m" << '\n';
	gotoxy(20, 5); cout << "[1;36;44m�� [33;40m�� �w �w �w �w �w �w �w �w ��  [37m  �A�q �A�q �A�q �A�q �A�q �A�q �A�q �A�q �A�q [32m�� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 6); cout << "[1;32;44m�� [40m�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 7); cout << "[1;32;44m�� [;35m���i�i�i�i[1;45m�� [32;40m�� [;35m��[1;45m�� [;35m��[1;45m�� [;35m��[1;45m�� [32;40m�� [;35m���i�i�i�i[1;45m�� [32;40m�� �� [;35m���i�i[1;45m�� [;35m��[1;32m�� [;35m���i�i�i�i[1;45m�� [32;40m�� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 8); cout << "[1;32;44m�� [31;40m�i�i�i�i�i[;35m��[1;32m�� [31m�i[;35m�i[1;31m�i[;35m�i[1;31m�i[;35m�i[1;32m�� [31m�i�i�i�i�i[;35m��[1;32m�� [31m���i�i�i[45m��[35m�� [32;40m�� [31m�i�i�i�i�i[;35m��[1;32m�� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 9); cout << "[1;32;44m�� [40m�� �� [31m�i[;35m�i[1;32m�� �� �� [31m�i[;35m�i[1;31m�i[;35m�i[1;31m�i[;35m�i[1;32m�� �� �� [31m�i[;35m�i[1;32m�� �� �� [31m�i[;35m�i[1;32m�� �� [31m�i[;35m��[1;32m�� [31m�i[35;45m�� [;35m�i�i�i[1;45m�� [32;40m�� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 10); cout << "[1;32;44m�� [40m�� �� [31m�i[;35m�i[1;32m�� �� �� [31m�i[;35m�i[1;31m�i[;35m�i[1;31m�i[;35m�i[1;32m�� �� �� [31m�i[;35m�i[1;32m�� �� �� [31m�i[;35m�i[1;32m�� �� [;35m��[1;45m�� [32;40m�� [31m�i�i�i�i�i[;35m��[1;32m�� �� �� [1;36;44m�� [m" << '\n';
	gotoxy(20, 11); cout << "[1;32;44m�� [40m�� �� [31m�i[;35m�i[1;32m�� �� �� [31m�i[35;45m�� [31;40m�i[35;45m�� [31;40m�i[;35m�i[1;32m�� [;35m���i[1;31m�i[1;35;45m�� [;35m�i[1;45m�� [32;40m�� [31m�i[35;45m�� [;35m�i�i[1;31m�i[;35m��[1;32m�� [31m�i[35;45m�� [;35m�i�i�i[1;45m�� [32;40m�� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 12); cout << "[1;32;44m�� [40m�� �� [31m�i[;35m��[1;32m�� �� �� [31m�i�i�i�i�i[;35m��[1;32m�� [31m�i�i�i�i�i[;35m��[1;32m�� [31m���i�i�i��[32m�� �� [31m�i�i�i�i�i[;35m��[1;32m�� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 13); cout << "[1;32;44m�� [40m�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� [36;44m�� [m" << '\n';
	gotoxy(20, 14); cout << "[1;36;44m�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��               �� �� �� �� [m" << '\n';
	//------------------------------------------------------------------------------------------------------------------------------------------------
	gotoxy(0, 18); cout << "\t      �� 	      ������������������������������"; gotoxy(71, 18);	cout << "������������������" << "           �� " << "     ��   ��           " << endl;
	gotoxy(0, 19); cout << "\t      �� 	      �� ���������������������� ��";		gotoxy(71, 19);	cout << "    ��" << "               �� " << "     ��   ��   " << endl;
	gotoxy(0, 20); cout << "       ������������������������������        ��      ��      ��"; gotoxy(71, 20); cout << "    ��" << "\t         ����������" << "   �������������� " << endl;
	gotoxy(0, 21); cout << "       ��      ��      ��        ��      ��      ��";			gotoxy(71, 21); cout << "    ��" << "\t           ��      " << "��   �� " << endl;
	gotoxy(0, 22); cout << "       ��      ��      ��        ��      ��      ��";		 gotoxy(71, 22); cout << " \t\t  /�� \\" << "    ����������  " << endl;
	gotoxy(0, 23); cout << "       ��      ��      ��        �� ���������������������� ��"; gotoxy(71, 23); cout << "������������������" << "         / ��  \\" << "   ��   ��  " << endl;
	gotoxy(0, 24); cout << "       ��      ��      ��        ��      ��      �� "; gotoxy(71, 24); cout << "\t          ��" << "     /  ��   \\" << "  ����������   " << endl;
	gotoxy(0, 25); cout << "       ������������������������������        ��      �� �B   ��"; gotoxy(71, 25); cout << "������������������" << "       /   ��    \\" << " ��   ��" << endl;
	gotoxy(0, 26); cout << "	      ��	              ��      ��  �B  ��"; gotoxy(71, 26); cout << "   ����" << "               ��     " << "��������������      " << endl;
	gotoxy(0, 27); cout << "              ��               �� ���������������������� ��"; gotoxy(71, 27); cout << " ��  ��" << "               �� " << "     //  \\\\   " << endl;
	gotoxy(0, 28); cout << "              ��               ������������������������������"; gotoxy(70, 28); cout << "��    ����������" << "           �� " << "    //    \\\\    " << endl;
	gotoxy(0, initialy - 4);	cout << "----------------------------------------------------------------------------------------------------------------------";
	gotoxy(initialx, initialy);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	cout << menu[0];
	gotoxy(initialx, initialy + 1);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	cout << menu[1];
	gotoxy(initialx, initialy + 2); cout << menu[2];
	gotoxy(initialx, initialy + 3);	cout << menu[3];
	gotoxy(117, 29);
}
void up_gotoxy(int num)
{
	COORD pointup;
	pointup.X = initialx;  pointup.Y = initialy + num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	  
	cout << menu[num];
	pointup.X = initialx;
	if (num == 0)
		pointup.Y = initialy + num + 3;
	else
		pointup.Y = initialy + num - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	
	if (num == 0)
		cout << menu[3];
	else
		cout << menu[num - 1];
	gotoxy(117, 29);
}
void down_gotoxy(int num)
{
	COORD point;
	point.X = initialx; point.Y = initialy + num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//����k��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << menu[num];
	point.X = initialx; 	
	if (num == 3)
		point.Y = initialy + num - 3;
	else
		point.Y = initialy + num + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//���ϥ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	
	if (num == 3)
		cout << menu[0];
	else
		cout << menu[+1];
	gotoxy(117, 29);
}

