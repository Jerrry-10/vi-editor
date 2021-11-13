/** @file  position.h Page 1
Class to store a position in the editor's text in the form of x y coordinates.
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 8, 2021
*/
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

	/**Mutator for x
	@param newX  The new value to which x is to be set.
	@post  x == newX */
	void setX(int newX);

	/**Mutator for y
	@param newY  The new value to which y is to be set.
	@post  y == newY */
	void setY(int newY);

	/**Accessor for x
	@return  The value of x */
	int getX() const;

	/**Accessor for y
	@return  The value of y */
	int getY() const;

};