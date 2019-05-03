#include "ChessBasic.h"
class Horse : public chessBasic
{
public:
	Horse(void) {}
	bool isMovable(int, int, vector<vector<int> >);
};