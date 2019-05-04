#include "ChineseChess.h"
#include "start_menu.h"

int main()
{
	ChineseChess game;
	while (true)
	{
		menuprint();
		//主選單
		game.setMode();
		//執行動作
		game.action();
	}
	return 0;
}