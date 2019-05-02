#include <string>
#include <vector>
#include "chessBasic.h"
using namespace std;

class ChessBoard
{
public:
	//初始化棋盤
	ChessBoard(vector<vector<int>>,bool);
	//取得當前座標棋子
	int getChess(void);
	//取得當前下棋方
	bool getTurn(void);
	//改變下棋方
	void changeTurn(void);
	//取的當前X座標
	int getCurX(void);
	//取得當前Y座標
	int getCurY(void);
	//移動座標
	void changeCoordinate(void);
	//選擇要移動的旗子
	bool chooseChess(chessBasic**);
	//遊戲中按ESC叫出菜單
	void menu(void);
	//移動棋子
	int move(chessBasic*,int,int);
	//儲存每一首狀況
	void saveBoard(void);
	//儲存當前棋局在檔案中
	void saveFile(void);
	//悔棋
	void regret(void);
private:
	vector<vector<int>> curBoard;
	bool turn;
	int curX, curY;
};