#include "Change.h"
using std::string;

Change::Change()
{}

Change::Change (const Position& positionOfDeletedContents, const string& changedCharacters, char command, int lineNumber)
    :mPositionOfDeletedContents(positionOfDeletedContents), mChangedCharacters(changedCharacters), mCommand(command), mLineNumber(lineNumber)
{}

Position Change::getPositionOfDeletedContents() const
{
  return mPositionOfDeletedContents;
}

std::string Change::getChangedCharacters() const
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

void Change::setPositionOfDeletedContents(const Position& positionOfDeletedContents)
{
    mPositionOfDeletedContents = positionOfDeletedContents;
}

void Change::setChangedCharacters(const string& changedCharacters)
{
    mChangedCharacters = changedCharacters;
}

void Change::setCommand(char command)
{
    mCommand = command;
}

void Change::setLineNumber(int lineNumber)
{
    mLineNumber = lineNumber;
}