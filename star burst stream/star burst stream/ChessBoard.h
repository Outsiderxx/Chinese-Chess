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
	int getChess(int,int);
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
	//遊戲中按ESC叫出菜單
	int menu(void);
	//移動棋子
	int move(chessBasic*);
	//儲存每一首狀況
	void saveBoard(void);
	//儲存當前棋局在檔案中
	void saveFile(void);
	//悔棋
	void regret(void);
	//取得棋盤
	vector<vector<int>> getBoard(void);
	//畫出棋盤
	void printBoard(void);
	//重播
	void replay(void);
	//勝利
	void win(bool);
	//王對王
	bool kingMeetKing(vector<vector<int>>);
	//顯示當前選擇棋子
	void printChess(int);
	//戰況顯示
	void printStatus(int,int);
	//走棋提示
	void printHint(vector<vector<bool>>);
	void sethintBoard(vector<vector<bool>>);
	vector<vector<bool>> gethintBoard();
private:
	vector<vector<int>> curBoard;
 	vector<vector<vector<int>>> preBoard;
	vector<vector<bool>> hintBoard = { {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0} };
	bool turn;
	int curX, curY;
};