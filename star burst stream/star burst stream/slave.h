#include"chessBasic.h"
class slave :public chessBasic
{
public:
	slave(void) {}
	virtual bool isMovable(int, int, vector<vector<int> >);
};
