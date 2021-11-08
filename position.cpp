#include "position.h"

Position::Position() {
	x = 0;
	y = 0;
}

Position::Position(int incomingX, int incomingY) : x(incomingX), y(incomingY)
{
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