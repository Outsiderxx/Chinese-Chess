#include"chessBasic.h"

class Car :public chessBasic
{
public:
	Car(void) {}
	bool isMovable(int, int, vector<vector<int>>);
	vector<vector<bool> > hint(int, int, vector<vector<int>>);
};