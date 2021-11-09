#include "editor.h"
#include "LinkedList.h"
#include<iostream>
#include "position.h"

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

void editor::run() {
    char command = '\0';
    bool endProgram = false;
    Position userPosition;
   
    //Loop to process commands entered by user.
    while(!endProgram)
    {
        getch(command); //Do we need getwch? Depends on compiler.

        //Switch to execute the appropriate code depending on command entered.
        switch(command)
        {
            case 'x':
                deleteCurrentCharacter(userPosition);
            break;
            case ':'
                    //Create position object which denotes the first space on the fifth empty line (x=0, y= last line + 5).
                Position endOfFile (0, (lines.getLength() + 5) );

                    //Move cursor to bottom.
                placeCursorAt(endOfFile);
                
                cout << ':';
                
                //Process the user's end-of-file commands ('w' or 'q').
               endProgram = endOfFileCommand();
            break;
        }
}

void editor::writeToFile()
{
    ifstream outfile;
    outfile = ("test.txt");

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
    bool endProgram = false;
    getche(command);
    
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
