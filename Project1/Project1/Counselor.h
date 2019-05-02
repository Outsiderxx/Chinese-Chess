#include "ChessBasic.h"
class Counselor : public chessBasic
{
public:
	Counselor(int, int, int);
	bool isMovable(int, int, const int *board[]);
};


