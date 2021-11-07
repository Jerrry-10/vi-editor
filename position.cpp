#include "position.h"
#include <xmemory>
Position::Position() {
	x = 0;
	y = 0;
}

void Position::setX(int newX)
{
	x = newX;
}

void Position::setY(int newY)
{
	 y = newY;
}

int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
}

