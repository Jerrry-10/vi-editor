/**@file Change.h Page 1
Class to store the data pertaining to a change in the text file.
@author Kevin Reid, Jerry Aviles & Xhudita Istrefi
December 2, 2021
*/

#ifndef CHANGE_H
#define CHANGE_H

#include "Position.h"
#include <string>
using std::string;

	class Change
	{
	public:
	    
	    /**Default Constructor. 
	    @post  Instantiates object with default values in private section.
	    Note: They are dummy values which act as temporary placeholders for the real values.
	    */
	    Change();
	    
	    /** Constructor.
	    @param positionOfDeletedContents  The position in the text where the deleted contents were located.
	    @param changedCharacters  The line of text being altered.
	    @param command  The command entered by the user. Either 'x' to delete a single char or 'd' to delete a line.
	    @param lineNumber  The number of the line on which the change occurred.
	    @post  Object is constructed.
	    */
	    Change (const Position& positionOfDeletedContents, const string& changedCharacters, char command, int lineNumber);
	        
	    /**Accessor for mPositionOfDeletedContents.
	    @return  The value of mPositionOfDeletedContents.
	    */
	    Position getPositionOfDeletedContents() const;
	    
	    /**Accessor for mChangedCharacters.
	    @return  the value ofmChangedCharacters.
	    */
	    string getChangedCharacters() const;
	    
	    /**Accessor for mCommand.
	    @return  The value of mCommand.
	    */
	    char getCommand() const;
	    
	    /**Accessor for mLineNumber.
	    @return  the value of mLineNumber,
	    */
      	    int getLineNumber() const;

		//The following mutators are only recommended for use on Change objects which have been instantiated with
		//dummy values by the default constructor. Objects which have been given real values at instantiation should generally
		//NOT have their attributes reset.

		/**Mutator for mPositionOfDeletedContents
		@param positionOfDeletedContents  The Position where the deleted contents were located.
		@post  mPositionOfDeletedContents = positionOfDeletedContents
		*/
		void setPositionOfDeletedContents(const Position& positionOfDeletedContents);

		/**Mutator for mChangedCharacters
		@param changedCharacters  The string being altered.
		@post  mChangedCharacters = changedCharacters
		*/
		void setChangedCharacters(const string& changedCharacters);

		/**Mutator for mCommand
		@param command  The command entered by the user.
		@post  mCommand = command
		*/
		void setCommand(char command);

		/**Mutator for mLineNumber.
		@param lineNumber  The number of the line which was deleted or altered.
		@post  mLineNumber = lineNumber
		*/
		void setLineNumber(int lineNumber);


	private:
	    string mChangedCharacters = ""; //The line (string) on which the change took place.
	    Position mPositionOfDeletedContents; //default position is (0,0) See Position.cpp
            int mLineNumber = 1;	//The number of the line on which the deletion took place.
			char mCommand = 'x';//command entered by user, either 'x' or 'd'.
	};

#endif
