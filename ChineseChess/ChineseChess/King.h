#include "ChessBasic.h"

class King : public chessBasic
{
public:
	King(void) {}
	virtual bool isMovable(int, int, vector<vector<int>>);
	bool kingMeetKing(King&, vector<vector<int>>);
};
