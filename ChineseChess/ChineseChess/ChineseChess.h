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
	int gameMode;
	vector<vector<int>> playBoard;
	vector<vector<vector<int>>> oldBoard;
	bool turn;
};