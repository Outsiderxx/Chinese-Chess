#include "ChessBasic.h"
class Elephant : public chessBasic
{
public:
	Elephant(void) { moveCount = 0; }
	bool isMovable(int, int, vector<vector<int> >);
private:
	int moveCount;
};