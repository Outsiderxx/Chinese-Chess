#include <string>
#include <vector>
using namespace std;

class ChineseChess
{
public:
	ChineseChess() :gameMode(0) {}
	void setPlayBoard(string);
	void playGame(void);
	void action();
	void getManual();
	void exitGame();
	void setMode();
private:
	int gameMode = 0;
	vector<vector<int>> initialPlayBoard;
	bool initialTurn;
};