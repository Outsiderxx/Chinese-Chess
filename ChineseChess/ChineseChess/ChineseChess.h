#include <string>
using namespace std;

class ChineseChess
{
public:
	ChineseChess() :gameMode(0) {}
	bool playGame(string);
	void action();
	void getManual();
	void exitGame();
	void setMode();
private:
	int gameMode;
};