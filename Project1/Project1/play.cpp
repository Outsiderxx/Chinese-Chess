#include<iostream>
#include<fstream>
using namespace std;
void play()
{
	int board[10][9];
	fstream file;
	file.open("initial.txt");
	if (file.is_open())
	{
		//initial board
		//initial chess
		/*while(kbhit())
		{
			char ch;
			ch = get();
			if (ch == esc)
			{
				//(1) write board
				//(2) read board
				//(3) exit
			}
			else
			{
				/*�P�_�ӭt
			}
		}*/

		//�O�_�~��

	}
	else
	{
		cout << "stupid" << endl;
	}
}


	







