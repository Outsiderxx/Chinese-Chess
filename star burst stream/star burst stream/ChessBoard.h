#include <string>
#include <vector>
#include "chessBasic.h"
using namespace std;

class ChessBoard
{
public:
	//��l�ƴѽL
	ChessBoard(vector<vector<int>>,bool);
	//���o��e�y�дѤl
	int getChess(int,int);
	//���o��e�U�Ѥ�
	bool getTurn(void);
	//���ܤU�Ѥ�
	void changeTurn(void);
	//������eX�y��
	int getCurX(void);
	//���o��eY�y��
	int getCurY(void);
	//���ʮy��
	void changeCoordinate(void);
	//�C������ESC�s�X���
	int menu(void);
	//���ʴѤl
	int move(chessBasic*);
	//�x�s�C�@�����p
	void saveBoard(void);
	//�x�s��e�ѧ��b�ɮפ�
	void saveFile(void);
	//����
	void regret(void);
	//���o�ѽL
	vector<vector<int>> getBoard(void);
	//�e�X�ѽL
	void printBoard(void);
	//����
	void replay(void);
	//�ӧQ
	void win(bool);
	//�����
	bool kingMeetKing(vector<vector<int>>);
	//��ܷ�e��ܴѤl
	void printChess(int);
	//�Ԫp���
	void printStatus(int,int);
	//���Ѵ���
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