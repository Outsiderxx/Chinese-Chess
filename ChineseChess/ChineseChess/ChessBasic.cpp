#include "chessBasic.h"

void chessBasic::setx(int nowx)
{
	x = nowx;
}
void chessBasic::sety(int nowy)
{
	y = nowy;
}
int chessBasic::getx()
{
	return x;
}
int chessBasic::gety()
{
	return y;
}

bool chessBasic::getCamp()
{
	return camp;
}

void chessBasic::setCamp(bool whichCamp)
{
	camp = whichCamp;
}