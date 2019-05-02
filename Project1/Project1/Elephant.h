#include "ChessBasic.h"
class Elephant : public chessBasic
{
public:
	Elephant(int,int,int);
	bool isMovable(int, int, vector<vector<int> >);
private:
	int moveCount;
};