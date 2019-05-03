#include <string>
#include <vector>
using namespace std;

class ChineseChess
{
public:
	ChineseChess() :gameMode(0) {}
	//開始
	void playGame(void);
	//設定模式
	void setMode();
	//依照gameMode做相對應的動作
	void action();
	//棋局設定
	void setPlayBoard(string);
	//取得說明書
	void getManual();
	//離開遊戲
	void exitGame();
private:
	int gameMode = 0;
	vector<vector<int>> initialPlayBoard;
	bool initialTurn;
};