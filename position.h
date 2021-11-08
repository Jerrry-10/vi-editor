#pragma once

class Position
{
private:
	int x;
	int y;
public:
	/** Default constructor
	@post x == 0, y == 0 */
	Position();

	/**Constructor
	@param incomingX  The x-coordinate value.
	@param incomingY  The y-coordinate value.
	@post  x == incomingX, y == incomingY */
	Position(int incomingX, int incomingY);

	void setX(int newX);

	void setY(int newY);

	int getX() const;

	int getY() const;

};