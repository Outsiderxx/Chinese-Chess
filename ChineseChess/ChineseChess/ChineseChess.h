#include <string>
#include <vector>
using namespace std;

class ChineseChess
{
public:
	ChineseChess() :gameMode(0) {}
	//�}�l
	void playGame(void);
	//�]�w�Ҧ�
	void setMode();
	//�̷�gameMode���۹������ʧ@
	void action();
	//�ѧ��]�w
	void setPlayBoard(string);
	//���o������
	void getManual();
	//���}�C��
	void exitGame();
private:
	int gameMode = 0;
	vector<vector<int>> initialPlayBoard;
	bool initialTurn;
};