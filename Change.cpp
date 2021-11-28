#include "Change.h"

Change::Change()
{}

Change::Change (const Position& positionOfDeletedContents, const string& changedCharacters, char command)
:mPositionOfDeletedContents(positionOfDeletedContents), mChangedCharacters(changedCharacters), mCommand(command), mLineNumber(lineNumber)
{}

Position Change::getPositionOfDeletedContents() const
{
  return mPositionOfDeletedContents;
}

string Change::getChangedCharacters() const
{
  return mChangedCharacters;
}  

char Change::getCommand() const
{
  return mCommand;
}

int Change::getLineNumber() const
{
  return mLineNumber;
}
