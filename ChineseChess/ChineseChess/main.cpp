#include "ChineseChess.h"

int main()
{
	ChineseChess game;
	while (true)
	{
		//主選單
		game.setMode();
		//執行動作
		game.action();
	}
	return 0;
}