/** @file  editor.cpp Page 1
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 16, 2021
*/
#include "LinkedStack.h"
#include "editor.h"
#include "LinkedList.h"
#include<iostream>
#include "position.h"
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;

void placeCursorAt(Position coordinate) {

    COORD coord;

    coord.X = coordinate.getX();

    coord.Y = coordinate.getY();

    SetConsoleCursorPosition(

        GetStdHandle(STD_OUTPUT_HANDLE),

        coord);

}

void editor::moveUp() {
    if (userPosition.getY() - 1 < 0) { //If out of bounds, do nothing.

    }
    else if (userPosition.getY() != -1) {
        userPosition.setY(userPosition.getY() - 1); // Sets the position to be 1 higher.
    }
    
    /* If the old line is longer than the new line, then when cursor moves up, its x coordinate could be out of bounds
    for the new line. If so, this if statement resets the x coordinate to the end of the new line. */
    int length = lines.getEntry(userPosition.getY() + 1).length(); //get Length of current line
    if (userPosition.getX() > length - 1) {
        userPosition.setX(length - 1);
    }
    placeCursorAt(userPosition); //Places the cursor at the updated position
    // else error
}
void editor::moveDown() {
    if (userPosition.getY() + 2 > lines.getLength()) { //If out of bounds, do nothing.

    }
    else if (userPosition.getY() != -1) {
        userPosition.setY(userPosition.getY() + 1); //Set position to be 1 lower.

    }

    /* If the old line is longer than the new line, then when cursor moves down, its x coordinate could be out of bounds
    for the new line. If so, this if statement resets the x coordinate to the end of the new line. */
    int length = lines.getEntry(userPosition.getY() + 1).length(); //get Length of current line
    if (userPosition.getX() > length - 1) {
        userPosition.setX(length - 1);
    }
    // cout << lines.getLength();
    placeCursorAt(userPosition);
}
void editor::moveLeft() {
    if (userPosition.getX() > 0) { //Check for out of bounds
        userPosition.setX(userPosition.getX() - 1); //Set position to be 1 to the left.
    }

    placeCursorAt(userPosition); //Places the cursor at the updated position
}
void editor::moveRight() {

    //get Length of current line
    int length = lines.getEntry(userPosition.getY() + 1).length();
    if (userPosition.getX() > length - 1) {
        //If out of bounds, do nothing.
    }
    if (userPosition.getX() < length - 1) {
        userPosition.setX(userPosition.getX() + 1); //Set position to be 1 to the right.
    }
    placeCursorAt(userPosition);
}
void editor::deleteCurrentLine()
{
    int currentLine = userPosition.getY() + 1; //Need +1 because list Lines starts at 1 but coordinates in class Position start at 0.
    
    lines.remove(currentLine); //Delete the line. Current line = next line.

    //Get Length of new current line.
    string thisLine = lines.getEntry(currentLine);
    int length = thisLine.length();

    /* If the line to delete was longer than the next line, then after deletion, cursor's x coordinate could be out of bounds
    for the newly current line. If so, this if statement resets the x coordinate to the end of the line. */
    if (userPosition.getX() > (length -1) ) //string indices and coordinates both begin at 0, not 1.
    {
        userPosition.setX(length -1);
        placeCursorAt(userPosition);
    }
}

editor::editor() {}
editor::editor(string file) {

    //   cout << "File: " << file << endl;
    ifstream in;
    in.open(file);
    if (!in) {
        cerr << "File not found..." << endl;
        exit(1);
    }
    else {
        string line;
        int lineNumber = 1;
        while (!in.eof()) {
            getline(in, line);
            // cout << line << endl; // This is for testing to see what is being read
            lines.insert(lineNumber, line); // Puts the lines into the linkedlist
            lineNumber++; //Increases the number so I can insert the next lines into the linkedlist
        }
    }
    in.close();
    displayLines();
}

//Page 2

void editor::displayLines() {
    system("cls");

    if (!lines.isEmpty()) {
        int numberOfLines = lines.getLength();
        
        //Save cursor's position for future use.
        int storeX = userPosition.getX(), storeY = userPosition.getY();

        //Move cursor to beginning of text.
        userPosition.setX(0);
        userPosition.setY(0);

        //Loop to print each line to console. Note that the first position in the LinkedList lines is 1, not 0.
        for (int i = 1; i < numberOfLines + 1; i++)
        {
            cout << lines.getEntry(i) << endl;

        }

        //Return cursor to original position.
        userPosition.setX(storeX);
        userPosition.setY(storeY);
        placeCursorAt(userPosition);
    }
}

void editor::writeToFile()
{
    ofstream outfile;

    outfile.open("test.txt");
    int numberOfLines = lines.getLength();
    //Loop to write each line to the output file.
    for (int i = 1; i < numberOfLines + 1; i++)
    {
        outfile << lines.getEntry(i);
        outfile << endl;
    }

    outfile.close();
}

void editor::deleteCurrentCharacter(Position userPosition)
{
    string tempString = "";
    int lineNumber = userPosition.getY() + 1;
    int characterPosition = userPosition.getX();

    //delete current char.
    tempString = lines.getEntry(lineNumber);
    tempString.erase(characterPosition, 1);

    //Replace original string with altered string.
    lines.replace(lineNumber, tempString);
}

bool editor::endOfFileCommand()
{
    char command = '\0';

    command = _getche();
    if (command == 'w')
    {
        writeToFile();
        changesWereMadeButNotSaved = false;
        placeCursorAt(userPosition);
    }
    else if (command == 'q')
    {
        if (!changesWereMadeButNotSaved) //Quits without :q! IF there are no unsaved changes.
        {
            endProgram = true;
        }
        else
        {
            cout << "\n\nChanges have NOT been saved. Enter :q! to quit anyway. Enter any other key to continue: ";
            string nextCommand;
            getline(cin >>ws, nextCommand);

            if (nextCommand == ":q!")
            {
                endProgram = true;
            }
            else
            {
                placeCursorAt(userPosition);
            }
            
        }
    }

    return endProgram;
}

void editor::run() {
    char command = '\0';

    //Loop to process commands entered by user.
    while (!endProgram)
    {
        command = _getch();

        //Switch to execute the appropriate code depending on command entered.
        switch (command)
        {
        case 'x':
            deleteCurrentCharacter(userPosition);
            changesWereMadeButNotSaved = true;
            displayLines(); //Allows user to see change in real time.
            break;
        case 'j': case KEY_DOWN:
            moveDown();
            break;
        case 'k': case KEY_UP:
            moveUp();
            break;
        case 'h': case KEY_LEFT:
            moveLeft();
            break;
        case 'l': case KEY_RIGHT:
            moveRight();
            break;
        case 'd':
            command = _getch();
            if (command == 'd')
            {
                deleteCurrentLine();
                changesWereMadeButNotSaved = true;
                displayLines(); //Allows user to see change in real time.
                
            }
            //else do nothing.
            break;
        case 'u':
                //undo
        case ':':
            //Create position object which denotes the first space on the fifth empty line (x=0, y= last line + 5).
            Position endOfFile(0, (lines.getLength() + 5));

            //Move cursor to bottom.
            placeCursorAt(endOfFile);

            cout << ':';

            //Process the user's end-of-file command ('w' or 'q').
           
            endProgram = endOfFileCommand();
            break;
        
        }//End switch
    }//End while
}
