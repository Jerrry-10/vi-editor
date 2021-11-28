#ifndef CHANGE_H
#define CHANGE_H

#include "Position.h"
using std::string

	class Change
	{
	public:
	    
	    //Default Constructor.
	    Change();
	    
	    /** Constructor.
	    @param positionOfDeletedContents  The position in the text where the deleted contents were located.
	    @param changedCharacters  The single character OR line of text deleted.
	    @param command  The command entered by the user. Either 'x' to delete a single char or 'd' to delete a line.
	    @post  Object is constructed.
	    */
	    Change (const Position& positionOfDeletedContents, const string& changedCharacters, char command);
	        
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
	

	private:
	    string mChangedCharacters; //Can be a line or a single char.
	    Position mPositionOfDeletedContents;
      	    int mLineNumber;
	    char mCommand; //'x' or 'd'
	}

#endif
