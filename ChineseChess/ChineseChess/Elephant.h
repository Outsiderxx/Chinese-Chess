#include "ChessBasic.h"
class Elephant : public chessBasic
{
public:
	Elephant(void) {}
    bool isMovable(int, int, vector<vector<int>>);
	vector<vector<bool> > hint(int, int, vector<vector<int> >);
private:
	int moveCount;
};