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

    cout << "File: " << file << endl;
    ifstream in;
    in.open(file);
    if(!in) {
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
/*void editor::run() {

    char command = '\0';
    bool endProgram = false;
    
    //Loop to process commands entered by user.
    while(!endProgram)
    {
        getch(command); //Do we need getwch?
        
        //Switch to execute the appropriate code depending on command entered.
        switch(command)
        {
            case 'x':
                //delete current char. Can use parameterized version of the string function erase
            break;
            case ':'
                    //Create position object which denotes the first space on the first empty line.
                Position endOfFile (0, (lines.getLength() + 1) );
                    
                    //Move cursor to bottom. 
                placeCursorAt(endOfFile);
                
                if (command == 'w')
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
                else if (command == 'q')
                    {
                        endProgram = true;
                    }
            break;
        }

}
*/


//void editor::
