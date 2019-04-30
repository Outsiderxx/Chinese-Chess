#include "ChessBasic.h"
class Elephant : public chessBasic
{
public:
	Elephant();
	Elephant(int,int,int);
	~Elephant();
	void move(int, int);
private:
	bool camp;
	int moveCount;
};


