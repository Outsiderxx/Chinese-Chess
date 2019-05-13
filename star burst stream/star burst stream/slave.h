#include"chessBasic.h"
class slave :public chessBasic
{
public:
	slave(void) {}
	bool isMovable(int, int, vector<vector<int> >);
	vector<vector<bool> > hint(int, int, vector<vector<int> >);
};
