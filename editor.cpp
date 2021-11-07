#include "editor.h"
#include "LinkedList.h"
#include<iostream>

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
        cout << "File not found..." << endl;
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
void editor::DisplayLines() {
    if (!lines.isEmpty()) {
        int numoflines = lines.getLength();
        for (int i = 1; i < numoflines; i++)
        {
            cout << lines.getEntry(i) << endl;
        }
    }
}
/*void editor::run() {

}
*/


//void editor::