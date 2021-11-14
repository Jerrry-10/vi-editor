/** @file  editor.cpp Page 1
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 8, 2021
*/
#include "editor.h"
#include "LinkedList.h"
#include<iostream>
#include "position.h"
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75
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
    if (userPosition.getY() - 1 < 0) {
  
    }
    else if (userPosition.getY() != -1) {
        userPosition.setY(userPosition.getY() - 1); // Sets the position to be 1 higher.
    }
    placeCursorAt(userPosition); //Places the cursor at the updated position
    // else error
}
void editor::moveDown() {
    if (userPosition.getY() + 2 > lines.getLength()) {

    }
    else if (userPosition.getY() != -1) {
        userPosition.setY(userPosition.getY() + 1);
       
    }
   // cout << lines.getLength();
    placeCursorAt(userPosition);
}
void editor::moveLeft() {
    if (userPosition.getX() > 0) {
        userPosition.setX(userPosition.getX() - 1);
    }
  
    placeCursorAt(userPosition); //Places the cursor at the updated position
}
void editor::moveRight() {
    if (userPosition.getX() >= 0) { //THIS LINE IS FAULTY. x MUST NOT EXCEED MAXIMUM POSITION
        userPosition.setX(userPosition.getX() + 1);      
    }
    placeCursorAt(userPosition);
}/*
void editor::deleteCurrentLine()
{
    string currentLine = userposition.getY() + 1; //Need +1 because list Lines starts at 1 but coordinates in class Position start at 0? Not sure.
    lines.remove(currentLine);
    displayLines(); //Show change.
}
*/
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

void editor::displayLines() {

    if (!lines.isEmpty()) {
        int numberOfLines = lines.getLength();
        for (int i = 1; i < numberOfLines + 1; i++)
        {
            cout << lines.getEntry(i) << endl;
           
        }
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
    char command;
    bool endProgram = false;

    command = _getche();
    if (command == 'w')
    {
        writeToFile();
    }
    else if (command == 'q')
    {
        endProgram = true;
    }
    return endProgram;
}

void editor::run() {
    char command = '\0';
    bool endProgram = false;

    //Loop to process commands entered by user.
    while (!endProgram)
    {
        command = _getch();

        //Switch to execute the appropriate code depending on command entered.
        switch (command)
        {
        case 'x': //BUG. Does not work properly if you move the cursor first.
            deleteCurrentCharacter(userPosition);
            displayLines(); //allows user to see change.
            break;
        case 'j': case KEY_DOWN:
            //case downArrow :
                moveDown();
                
            break;
        case 'k': case KEY_UP:
            //case upArrow :
                moveUp();
                
            break;
        case 'h': case KEY_RIGHT:
            //case leftArrow :
                moveLeft();
            break;
        case 'l': case KEY_LEFT:
            //case rightArrow :
               moveRight();
            break;
        case 'd':
            command = _getch();
            if (command == 'd')
            {
                //deleteCurrentLine();
            }
            //else do nothing.
            break;
            case 'q': //BUG: It's supposed to be ':', THEN 'q'. We should do this in endOfFileCommand(), not here.
            command = _getch();
            if (command == '!') {
                Position endOfFile(0, (lines.getLength() + 5));
                placeCursorAt(endOfFile);
                endProgram = true;
            }
            break;
        case ':':
            //Create position object which denotes the first space on the fifth empty line (x=0, y= last line + 5).
            Position endOfFile(0, (lines.getLength() + 5));

            //Move cursor to bottom.
            placeCursorAt(endOfFile);

            cout << ':';

            //Process the user's end-of-file commands ('w' or 'q').
            while (!endProgram)
            {
                endProgram = endOfFileCommand();
            }
            break;
        }
    }
}
