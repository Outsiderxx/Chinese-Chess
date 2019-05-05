#include <string>
#include <vector>
using namespace std;

class ChineseChess
{
public:
	ChineseChess() :gameMode(0) {}
	//�i��C��
	void playGame(void);
	//��ܥ\��
	void setMode();
	//�̷�gameMode���۹������ʧ@
	void action();
	//�ѧ��]�w
	bool setPlayBoard(string);
	//���o������
	void getManual();
	//���}�C��
	void exitGame();
	//�w���ѽL
	void printBoard(void);
private:
	int gameMode = 0;
	//��l�ѽL
	vector<vector<int>> initialPlayBoard;
	//��l�X���
	bool initialTurn;
};