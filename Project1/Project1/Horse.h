#include "ChessBasic.h"
class Horse : public chessBasic
{
public:
	Horse(int, int, int);
	bool isMovable(int, int, vector<vector<int> >);
};