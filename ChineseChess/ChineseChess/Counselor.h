#include "ChessBasic.h"
class Counselor : public chessBasic
{
public:
	Counselor(void) {}
	bool isMovable(int, int, vector<vector<int> >);
	vector<vector<bool> > hint(int, int, vector<vector<int> >);
};


