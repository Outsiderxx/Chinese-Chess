#include"chessBasic.h"

class Car :public chessBasic
{
public:
	Car(void) {}
	virtual bool isMovable(int, int, vector<vector<int>>);
};