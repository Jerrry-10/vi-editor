#pragma once

class Position
{
private:
	int x;
	int y;
public:
	Position();
	void setX(int newX);
	void setY(int newY);
	int getX() const;
	int getY() const;

};

