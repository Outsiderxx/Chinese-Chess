#include "ChessBasic.h"
class King : public chessBasic
{
public:
	King(int, int, int);
	bool isMovable(int, int, const int *board[]);
	bool kingMeetKing(King&, const int *board[]);
};