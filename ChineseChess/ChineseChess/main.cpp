#include "ChineseChess.h"
#include "start_menu.h"

int main()
{
	ChineseChess game;
	while (true)
	{
		menuprint();
		//�D���
		game.setMode();
		//����ʧ@
		game.action();
	}
	return 0;
}