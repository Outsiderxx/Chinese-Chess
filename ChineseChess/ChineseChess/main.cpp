#include "ChineseChess.h"

int main()
{
	ChineseChess game;
	while (true)
	{
		game.setMode();
		game.action();
	}
	return 0;
}