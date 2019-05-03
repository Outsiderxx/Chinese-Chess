#include "ChessBasic.h"
class Counselor : public chessBasic
{
public:
	Counselor(int, int, int);
	bool isMovable(int, int, vector<vector<int> >);
};


