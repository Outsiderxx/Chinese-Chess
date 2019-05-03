#include "ChessBasic.h"
class Counselor : public chessBasic
{
public:
	Counselor(void) {}
	virtual bool isMovable(int, int, vector<vector<int>>);
};