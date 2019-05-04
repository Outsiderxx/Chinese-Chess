#include "start_menu.h"
#define initialx 54.5
#define initialy 21
const string menu[4] = { "¶}©l¹CÀ¸", "Å×¨תÀÉ®×" ,"¾Þ§@»¡©ת" ,"  Âק¶}  " };			//¿ן³זconst¥‏°ל

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
	cout << "\t\t";	cout << " 	   שר 	       שÝששששששששששששששששששששששששששש‗" << "\t      שששששששששÞשששששששש" << "\t          שר " << "     שר   שר           " << endl;
	cout << "\t\t"; cout << "	   שר 	       שר שששששששששששÞשששששששששש שר" << "\t          שר" << "\t          שר " << "     שר   שר   " << endl;
	cout << "\t\t"; cout << "    שÝשששששששששששששבששששששששששששש‗    שר      שר      שר" << "\t          שר" << "\t        שששששבשששש" << "   שששבשששששששבשש " << endl;
	cout << "\t\t"; cout << "    שר	   שר      שר    שר      שר      שר" << "\t          שר" << "\t          שר      " << "שר   שר " << endl;
	cout << "\t\t"; cout << "    שר	   שר      שר    שר      שר      שר" << "\t\t\t         /שר \\" << "    שאשששששששג  " << endl;
	cout << "\t\t"; cout << "    שר	   שר      שר    שר שששששששששששבשששששששששש שר" << "\t      שששששששששששששששששש" << "\t        / שר  \\" << "   שר   שר  " << endl;
	cout << "\t\t"; cout << "    שר	   שר      שר    שר      שר      שר " << "\t\t         ¢­" << "     /  שר   \\" << "  שאשששששששג   " << endl;
	cout << "\t\t"; cout << "    שדשששששששששששששבשששששששששששששו    שר      שר ¢B   שר" << "\t      שששששששששבשששששששש" << "\t      /   שר    \\" << " שר   שר" << endl;
	cout << "\t\t"; cout << "	   שר	       שר      שר  ¢B  שר" << "\t         ¢¬שר" << "\t          שר     " << "שששהשששששששהשש      " << endl;
	cout << "\t\t"; cout << "	   שר	       שר שששששששששששהשששששששששש שר" << "\t       ¢¬  שר" << "\t          שר " << "     //  \\\\   " << endl;
	cout << "\t\t"; cout << "	   שר	       שדשששששששששששששששששששששששששששו" << "\t     ¢¬    שדשששששששש" << "\t          שר " << "    //    \\\\    " << endl;
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//­ל¦לÂkÁÙ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << menu[num + 1];
	pointup.X = initialx;  pointup.Y = initialy + num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//¨ל¦ל¤Ï¥Õ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << menu[num];
	gotoxy(initialx + 64.5, initialy + 8);
}
void down_gotoxy(int num)		
{
	COORD point;
	point.X = initialx; point.Y = initialy + num - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//­ל¦לÂkÁÙ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);		cout << menu[num - 1];
	point.X = initialx; point.Y = initialy + num;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//¨ל¦ל¤Ï¥Õ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);		cout << menu[num];
	gotoxy(initialx + 64.5, initialy + 8);
}
int menu_control()		//¿ן³ז±±¨מ
{
	char key;	int no = 0;		bool enter_check = 0;
	while (!enter_check)		//¾Þ§@×½¨לenter
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
		case 72:			//read ¤ט¦V¤W  
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
		case 80:			//read ¤ט¦V¤U
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
