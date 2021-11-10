/** @file  editor.cpp Page 1
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 8, 2021
*/
#include "editor.h"
#include "LinkedList.h"
#include<iostream>
#include "position.h"
#include <conio.h>

using namespace std;

void placeCursorAt(Position coordinate) {

    COORD coord;

    coord.X = coordinate.getX();

    coord.Y = coordinate.getY();

    SetConsoleCursorPosition(

        GetStdHandle(STD_OUTPUT_HANDLE),

        coord);

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

void editor::displayLines() {

    if (!lines.isEmpty()) {
        int numberOfLines = lines.getLength();

        for (int i = 1; i < numberOfLines + 1; i++)
        {
            cout << lines.getEntry(i) << endl;
        }
        Position userPosition;
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
    }

    outfile.close();
}

void editor::deleteCurrentCharacter(Position userPosition)
{
    string tempString = "";
    int lineNumber = userPosition.getY();
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
    command = _getch();

//editor.cpp Page 2
    
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
    Position userPosition;

    //Loop to process commands entered by user.
    while (!endProgram)
    {
         command = _getch(); //Do we need getwch? Depends on compiler.

        //Switch to execute the appropriate code depending on command entered.
        switch (command)
        {
        case 'x':
            deleteCurrentCharacter(userPosition);
            displayLines(); //allows user to see change.
            break;
        case ':':
                //Create position object which denotes the first space on the fifth empty line (x=0, y= last line + 5).
                Position endOfFile(0, (lines.getLength() + 5));

                //Move cursor to bottom.
                placeCursorAt(endOfFile);

                cout << ':';

                //Process the user's end-of-file commands ('w' or 'q').
                while(!endProgram)
                {
                    endProgram = endOfFileCommand();
                }
                break;
        }
    }
}
