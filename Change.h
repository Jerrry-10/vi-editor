#include "Position.h"

class Change
{
public:
    
    Change();
    
    Position getPositionOfDeletedContents() const;
    
    void setPositionOfDeletedContents(const Position& positionOfDeletedContents);
    
    string getChangedCharacters() cosnt;
    
    void setChangedCharacters(const string& changedCharacters);

private:
    string mChangedCharacters; //Can be a line or a single char?
    Position mPositionOfDeletedContents;
}
