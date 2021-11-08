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
        int linenum = 1;
        while (!in.eof()) { 
            getline(in, line);
           // cout << line << endl; // This is for testing to see what is being read
            lines.insert(linenum, line); // Puts the lines into the linkedlist
            linenum++; //Increases the number so I can insert the next lines into the linkedlist
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
    }
}
/*void editor::run() {

    char command = '\0';
    bool endProgram = false;
    
    //Create position object which denotes the first space on the first empty line.
    Position endOfFile (0, (lines.getLength() + 1) );
    
    while(!endProgram)
    
    {
        getch(command); //Do we need getwch?
        
        switch(command)
        {
            case 'x':
                //delete current char. Can use parameterized version of the string function erase
            break;
            case ':'
                //Move cursor to bottom. 
                placeCursorAt(endOfFile);
                if (command == 'w')
                {
                    //call function to write to file.
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
