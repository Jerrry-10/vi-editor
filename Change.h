#include "Position.h"

class Change
{
public:
    
    Change();
    
    Change (const Position& positionOfDeletedContents, const string& changedCharacters);
        
    Position getPositionOfDeletedContents() const;
    
    string getChangedCharacters() const;
    
    char getCommand() const;

private:
    string mChangedCharacters; //Can be a line or a single char?
    Position mPositionOfDeletedContents;
    char mCommand; //'x' or 'd'
}
