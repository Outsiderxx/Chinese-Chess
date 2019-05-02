#include <string>
#include <vector>
#include "chessBasic.h"
using namespace std;

class ChessBoard
{
public:
	ChessBoard(string);
	int getChess(void);
	bool getTurn(void);
	void changeTurn(void);
	int getCurX(void);
	int getCurY(void);
	void changeCoordinate(void);
	void chooseChess(chessBasic*);
	void menu(void);
	int move(void);
private:
	vector<vector<int>> curBoard;
	bool turn;
	int curX, curY;
};