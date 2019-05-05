#include "start_menu.h"
#define initialx 54.5
#define initialy 21
const string menu[4] = { "¶}©l¹CÀ¸", "Åª¨úÀÉ®×" ,"¾Þ§@»¡©ú" ,"  Â÷¶}  " };			//¿ï³æconst¥þ°ì

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
	gotoxy(20, 2); cout << "[1;36;44mùÝ ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùù ùß [m" << '\n';
	gotoxy(20, 3); cout << "[1;36;44mùø [37;40m[33;50m¢~ ¢w ¢w ¢w ¢w ¢w ¢w ¢w ¢w ¢w ¢w  [37m  ¡´ ±N¡´ ¤h¡´ ¶H¡´ ¨®¡´ °¨¡´ ¥]¡´ ¨ò¡´ ¨ò¡´       [36;44mùø [m" << '\n';
	gotoxy(20, 4); cout << "[1;36;44mùø [33;40m¢x Do it Again !!!!¢x   [37m  <[33m¡¶[37m¡á<[36m¡¶[37m¡á<[32m¡¶[37m¡á<[31m¡¶[37m¡á<[36m¡¶[37m¡á<[32m¡¶[37m¡á<[33m¡¶[37m¡á<[31m¡¶[37m¡á<[35m¡¶[37m¡á     [36;44mùø [m" << '\n';
	gotoxy(20, 5); cout << "[1;36;44mùø [33;40m¢¢ ¢w ¢w ¢w ¢w ¢w ¢w ¢w ¢w ¢£  [37m  ¢A¡q ¢A¡q ¢A¡q ¢A¡q ¢A¡q ¢A¡q ¢A¡q ¢A¡q ¢A¡q [32mùÝ ùù ùß [36;44mùø [m" << '\n';
	gotoxy(20, 6); cout << "[1;32;44mùà [40mùù ùÞ ùÞ ùÞ ùÞ ùÞ ùÞ ùù ùÞ ùù ùÞ ùù ùÞ ùÞ ùù ùÞ ùÞ ùÞ ùÞ ùÞ ùÞ ùÞ ùù ùÞ ùÞ ùÞ ùù ùÞ ùù ùÞ ùÞ ùÞ ùÞ ùÞ ùá ùß ùø [36;44mùø [m" << '\n';
	gotoxy(20, 7); cout << "[1;32;44mùø [;35m¢¨¢i¢i¢i¢i[1;45m¢¬ [32;40mùâ [;35m¢¨[1;45m¢¬ [;35m¢¨[1;45m¢¬ [;35m¢¨[1;45m¢¬ [32;40mùâ [;35m¢¨¢i¢i¢i¢i[1;45m¢¬ [32;40mùá ùå [;35m¢¨¢i¢i[1;45m¢¬ [;35m¢©[1;32mùø [;35m¢¨¢i¢i¢i¢i[1;45m¢¬ [32;40mùâ ùø ùø [36;44mùø [m" << '\n';
	gotoxy(20, 8); cout << "[1;32;44mùà [31;40m¢i¢i¢i¢i¢i[;35m¢«[1;32mùà [31m¢i[;35m¢i[1;31m¢i[;35m¢i[1;31m¢i[;35m¢i[1;32mùá [31m¢i¢i¢i¢i¢i[;35m¢«[1;32mùø [31m¢¨¢i¢i¢i[45m¢©[35m¢¬ [32;40mùá [31m¢i¢i¢i¢i¢i[;35m¢«[1;32mùø ùø ùø [36;44mùø [m" << '\n';
	gotoxy(20, 9); cout << "[1;32;44mùà [40mùá ùá [31m¢i[;35m¢i[1;32mùá ùÞ ùá [31m¢i[;35m¢i[1;31m¢i[;35m¢i[1;31m¢i[;35m¢i[1;32mùá ùá ùá [31m¢i[;35m¢i[1;32mùá ùÞ ùá [31m¢i[;35m¢i[1;32mùá ùá [31m¢i[;35m¢«[1;32mùà [31m¢i[35;45m¢¬ [;35m¢i¢i¢i[1;45m¢¬ [32;40mùâ ùø ùø [36;44mùø [m" << '\n';
	gotoxy(20, 10); cout << "[1;32;44mùà [40mùá ùá [31m¢i[;35m¢i[1;32mùá ùá ùá [31m¢i[;35m¢i[1;31m¢i[;35m¢i[1;31m¢i[;35m¢i[1;32mùá ùä ùá [31m¢i[;35m¢i[1;32mùá ùá ùá [31m¢i[;35m¢i[1;32mùá ùâ [;35m¢¨[1;45m¢¬ [32;40mùá [31m¢i¢i¢i¢i¢i[;35m¢«[1;32mùø ùø ùø [1;36;44mùø [m" << '\n';
	gotoxy(20, 11); cout << "[1;32;44mùà [40mùá ùá [31m¢i[;35m¢i[1;32mùá ùá ùá [31m¢i[35;45m¢¬ [31;40m¢i[35;45m¢¬ [31;40m¢i[;35m¢i[1;32mùâ [;35m¢¨¢i[1;31m¢i[1;35;45m¢¬ [;35m¢i[1;45m¢¬ [32;40mùá [31m¢i[35;45m¢¬ [;35m¢i¢i[1;31m¢i[;35m¢«[1;32mùà [31m¢i[35;45m¢¬ [;35m¢i¢i¢i[1;45m¢¬ [32;40mùâ ùø ùø [36;44mùø [m" << '\n';
	gotoxy(20, 12); cout << "[1;32;44mùà [40mùá ùá [31m¢i[;35m¢«[1;32mùà ùá ùá [31m¢i¢i¢i¢i¢i[;35m¢«[1;32mùà [31m¢i¢i¢i¢i¢i[;35m¢«[1;32mùø [31m¢ª¢i¢i¢i¢«[32mùÝ ùá [31m¢i¢i¢i¢i¢i[;35m¢«[1;32mùø ùø ùø [36;44mùø [m" << '\n';
	gotoxy(20, 13); cout << "[1;32;44mùà [40mùä ùä ùá ùù ùä ùä ùä ùá ùä ùä ùá ùä ùù ùä ùá ùä ùä ùá ùä ùù ùä ùù ùä ùá ùä ùù ùá ùä ùä ùä ùä ùä ùä ùù ùá ùå ùø [36;44mùø [m" << '\n';
	gotoxy(20, 14); cout << "[1;36;44mùã ùù ùù ùä ùù ùù ùù ùù ùä ùù ùù ùä ùù ùù ùù ùä ùù ùù ùä ùù ùù ùù ùù ùù ùä ùù ùù ùå               ùã ùù ùä ùå [m" << '\n';
	//------------------------------------------------------------------------------------------------------------------------------------------------
	gotoxy(0, 18); cout << "\t      ùø 	      ùÝùùùùùùùùùùùùùùùùùùùùùùùùùùùß"; gotoxy(71, 18);	cout << "ùùùùùùùùùÞùùùùùùùù" << "           ùø " << "     ùø   ùø           " << endl;
	gotoxy(0, 19); cout << "\t      ùø 	      ùø ùùùùùùùùùùùÞùùùùùùùùùù ùø";		gotoxy(71, 19);	cout << "    ùø" << "               ùø " << "     ùø   ùø   " << endl;
	gotoxy(0, 20); cout << "       ùÝùùùùùùùùùùùùùáùùùùùùùùùùùùùß        ùø      ùø      ùø"; gotoxy(71, 20); cout << "    ùø" << "\t         ùùùùùáùùùù" << "   ùùùáùùùùùùùáùù " << endl;
	gotoxy(0, 21); cout << "       ùø      ùø      ùø        ùø      ùø      ùø";			gotoxy(71, 21); cout << "    ùø" << "\t           ùø      " << "ùø   ùø " << endl;
	gotoxy(0, 22); cout << "       ùø      ùø      ùø        ùø      ùø      ùø";		 gotoxy(71, 22); cout << " \t\t  /ùø \\" << "    ùàùùùùùùùâ  " << endl;
	gotoxy(0, 23); cout << "       ùø      ùø      ùø        ùø ùùùùùùùùùùùáùùùùùùùùùù ùø"; gotoxy(71, 23); cout << "ùùùùùùùùùùùùùùùùùù" << "         / ùø  \\" << "   ùø   ùø  " << endl;
	gotoxy(0, 24); cout << "       ùø      ùø      ùø        ùø      ùø      ùø "; gotoxy(71, 24); cout << "\t          ¢­" << "     /  ùø   \\" << "  ùàùùùùùùùâ   " << endl;
	gotoxy(0, 25); cout << "       ùãùùùùùùùùùùùùùáùùùùùùùùùùùùùå        ùø      ùø ¢B   ùø"; gotoxy(71, 25); cout << "ùùùùùùùùùáùùùùùùùù" << "       /   ùø    \\" << " ùø   ùø" << endl;
	gotoxy(0, 26); cout << "	      ùø	              ùø      ùø  ¢B  ùø"; gotoxy(71, 26); cout << "   ¢¬ùø" << "               ùø     " << "ùùùäùùùùùùùäùù      " << endl;
	gotoxy(0, 27); cout << "              ùø               ùø ùùùùùùùùùùùäùùùùùùùùùù ùø"; gotoxy(71, 27); cout << " ¢¬  ùø" << "               ùø " << "     //  \\\\   " << endl;
	gotoxy(0, 28); cout << "              ùø               ùãùùùùùùùùùùùùùùùùùùùùùùùùùùùå"; gotoxy(70, 28); cout << "¢¬    ùãùùùùùùùù" << "           ùø " << "    //    \\\\    " << endl;
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//­ì¦ìÂkÁÙ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	  
	cout << menu[num];
	pointup.X = initialx;
	if (num == 0)
		pointup.Y = initialy + num + 3;
	else
		pointup.Y = initialy + num - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pointup);			//¨ì¦ì¤Ï¥Õ
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//­ì¦ìÂkÁÙ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << menu[num];
	point.X = initialx; 	
	if (num == 3)
		point.Y = initialy + num - 3;
	else
		point.Y = initialy + num + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);					//¨ì¦ì¤Ï¥Õ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);	
	if (num == 3)
		cout << menu[0];
	else
		cout << menu[+1];
	gotoxy(117, 29);
}

