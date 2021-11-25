#ifndef CHANGE_H
#define CHANGE_H

#include "Position.h"
using std::string

	class Change
	{
	public:
	    
	    Change();
	    
	    Change (const Position& positionOfDeletedContents, const string& changedCharacters, char command);
	        
	    Position getPositionOfDeletedContents() const;
	    
	    string getChangedCharacters() const;
	    
	    char getCommand() const;

      int getLineNumber() const;
	

	private:
	    string mChangedCharacters; //Can be a line or a single char?
	    Position mPositionOfDeletedContents;
      int mLineNumber;
	    char mCommand; //'x' or 'd'
	}

#endif
