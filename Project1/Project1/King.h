#include "ChessBasic.h"
class King : public chessBasic
{
public:
	King(int, int, int);
	bool isMovable(int, int, vector<vector<int> >);
	bool kingMeetKing(King&, const int *board[]);
};