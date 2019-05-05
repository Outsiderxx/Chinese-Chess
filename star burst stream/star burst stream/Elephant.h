#include "ChessBasic.h"
class Elephant : public chessBasic
{
public:
	Elephant(void) {}
	virtual bool isMovable(int, int, vector<vector<int>>);
private:
	int moveCount;
};