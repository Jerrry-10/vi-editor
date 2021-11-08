#pragma once

class Position
{
private:
	int x;
	int y;
public:
	Position();
	Position(int incomingX, int incomingY);
	void setX(int newX);
	void setY(int newY);
	int getX() const;
	int getY() const;

};

