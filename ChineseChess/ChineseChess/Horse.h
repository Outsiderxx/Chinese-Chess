#include "ChessBasic.h"
class Horse : public chessBasic
{
public:
	Horse(void) {}
	virtual bool isMovable(int, int, vector<vector<int>>);
};