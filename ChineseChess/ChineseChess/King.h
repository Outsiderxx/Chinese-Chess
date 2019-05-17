#include "ChessBasic.h"
class King : public chessBasic
{
public:
	King(void) {}
	bool isMovable(int, int, vector<vector<int> >);
	bool kingMeetKing(King&, vector<vector<int> >);
	vector<vector<bool> > hint(int, int, vector<vector<int> >);
};