#include "chessBasic.h"

class slave :public chessBasic
{
public:
	slave(int, int, int);
	bool isMovable(int, int);
};
