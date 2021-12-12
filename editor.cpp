/** @file  editor.cpp Page 1
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
December 12, 2021
*/
#include "editor.h"
#include "LinkedStack.h"
#include "LinkedList.h"
#include<iostream>
#include "position.h"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;

//Nonmember Functions used by class Editor:

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//Modified for templation by program authors.
//Authors' original comment section moved to function protoype in header file.

/*

template<class ItemType>
int binarySearch(const ItemType anArray[], int first, int last, ItemType target)
{
    int index;
    if (first > last)
        index = -1; // target not in original array
    else
    {
        // If target is in anArray, anArray[first] <= target <= anArray[last]
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid; // target found at anArray[mid]
        else if (target < anArray[mid])
            // Point X
            index = binarySearch(anArray, first, mid - 1, target);
        else
            // Point Y
            index = binarySearch(anArray, mid + 1, last, target);
    }  // end if

    return index;
}  // end binarySearch

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

// Listing 11-2.
//Authors' original comment section moved to function protoype in header file.

//#include <iostream>
//#include <string>

template<class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
    bool sorted = false; // False when swaps occur
    int pass = 1;
    while (!sorted && (pass < n))
    {
        // At this point, theArray[n+1-pass..n-1] is sorted
        // and all of its entries are > the entries in theArray[0..n-pass]
        sorted = true; // Assume sorted
        for (int index = 0; index < n - pass; index++)
        {
            // At this point, all entries in theArray[0..index-1]
            // are <= theArray[index]
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                // Exchange entries
                std::swap(theArray[index], theArray[nextIndex]);
                sorted = false; // Signal exchange
            } // end if
        }  // end for
        // Assertion: theArray[0..n-pass-1] < theArray[n-pass]

        pass++;
    }  // end while
}  // end bubbleSort

*/

void colorText(int value) {

    COORD coord;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    FlushConsoleInputBuffer(hConsole);

    SetConsoleTextAttribute(hConsole, value + 240);

}

//Page 2

void placeCursorAt(Position coordinate) {

    COORD coord;

    coord.X = coordinate.getX();

    coord.Y = coordinate.getY();

    SetConsoleCursorPosition(

        GetStdHandle(STD_OUTPUT_HANDLE),

        coord);

}

// Member functions of class Editor:

/*
void editor::initializeArray(string theArray[], const int size)
{
    ifstream infile;
    infile.open(mKeywordFile);

    if (infile.fail())
    {
        cerr << "Error. Unable to open keyword file. Goodbye!\n\n";
        exit(1);
    }
    else
    {
        for (int index = 0; index < size; index++)
        {
            infile >> theArray[index];

            // cout << theArray[index] << endl; Test code
        }
        infile.close();
    }

} */

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

//Page 3  

void editor::deleteCurrentLine()
{
    int currentLine = userPosition.getY() + 1; //Need +1 because list Lines starts at 1 but coordinates in class Position start at 0.

    lines.remove(currentLine); //Delete the line. Current line = next line.

    
   
    
    //Get Length of new current line.
    string thisLine = lines.getEntry(currentLine);
    int length = thisLine.length();

    /* If the line to delete was longer than the next line, then after deletion, cursor's x coordinate could be out of bounds
    for the newly current line. If so, this if statement resets the x coordinate to the end of the line. */
    if (userPosition.getX() > (length - 1)) //string indices and coordinates both begin at 0, not 1.
    {
        userPosition.setX(length - 1);
        placeCursorAt(userPosition);
    }
}

editor::editor() {
   // initializeArray(keywords, MAX_ARRAY);
   //bubbleSort(keywords, MAX_ARRAY);
    //Should not call fillKeywordTree() because default constructor cannot take string argument for
        //value of mKeywordFile.
}
editor::editor(string file, string keywordFile) {

    mTextFile = file;
    mKeywordFile = keywordFile;
    //   cout << "File: " << file << endl;
    ifstream in;
    in.open(mTextFile);
    if (!in) {
        cerr << "File not found..." << endl;
        exit(1);
    }
    else {

      //  initializeArray(keywords, MAX_ARRAY);
        //bubbleSort(keywords, MAX_ARRAY);
        
        //Use BinarySearchTree.add in loop to fill tree with keywords.
        fillKeywordTree();

        /*
            for (int i = 0; i < MAX_ARRAY; i++)
            {
                cout << keywords[i] << endl; //Test code
            }
            */

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

/*
void editor::displayLines() { //Iteration 2 version
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
*/

// Iteration 3-4 version

//Method provided by Dr. Sturm. Modified by program authors.
void editor::displayLines()
{
    int position;
    string nextLine, nextWord, line;
    system("CLS");

    // goes through each line in the linked list 
    for (position = 1; position <= lines.getLength(); position++)
    {
        nextLine = lines.getEntry(position);

        int i = 0;
        while (i < nextLine.length()) {
            string word;
            // isolate a word at a time (can contain underscores)
            if (isalpha(nextLine[i])) {
                while (isalpha(nextLine[i]) || nextLine[i] == '_') {
                    word += nextLine[i];
                    i++;
                }                
//Page 4
                //Replace binary search with a call to BinarySearchTree.contains(word);
              if ( !keywordTree.contains(word) )  //Added the ! as a bug fix. Otherwise, all NON-keywords are colored blue.
                    colorText(1);
                else
                    colorText(0);
                cout << word;
            }

            else {
                colorText(0);
                cout << nextLine[i];
                i++;
            }

        }

        cout << endl;
    }
    placeCursorAt(userPosition);
} // end displayLines

void editor::undoLastChange()
{
    string textToBeRestored = "";

    if (!stackOfChanges.isEmpty())	//else: Do nothing.
    {
        //Get most recent change and remove it from stack.
        Change changeToBeUndone = stackOfChanges.peek();
        // cout << changeToBeUndone.getCommand(); 
        stackOfChanges.pop();
        
        //Get the original x and y coordinates of the change, and set User Position to those values.
        int yCoordinateOfChangeToBeUndone = changeToBeUndone.getPositionOfDeletedContents().getY();
        int xCoordinateOfChangeToBeUndone = changeToBeUndone.getPositionOfDeletedContents().getX();
        userPosition.setX(xCoordinateOfChangeToBeUndone);
        userPosition.setY(yCoordinateOfChangeToBeUndone);

        //Restore the changes.
        if (changeToBeUndone.getCommand() == 'x')
        {
            //Place cursor at original position of the change.
            placeCursorAt(userPosition);

            //Remove the altered line (missing the deleted character) from the list lines.
            deleteCurrentLine();
            
            //Get the previous version of the line (including the deleted character).
            textToBeRestored = changeToBeUndone.getChangedCharacters();

            //Restore the previous version of the altered line (which includes the deleted character)
            //to its original position in the list lines.
            lines.insert(changeToBeUndone.getLineNumber(), textToBeRestored);

            changesWereMadeButNotSaved = true;

        }
        else if (changeToBeUndone.getCommand() == 'd')
        {
            //Get the deleted line.
            textToBeRestored = changeToBeUndone.getChangedCharacters();
            
            //Place cursor at original site of the change.
            placeCursorAt(userPosition);

            //  cout << "\n\n\n\n\n\n\n\n\n\n\n Hello";
            
            //Restore the deleted line to its original position.
            lines.insert(changeToBeUndone.getLineNumber(), textToBeRestored);
           
            changesWereMadeButNotSaved = true;
        }
        else
        {
            cerr << "Error. Invalid change was popped onto stack.\n\n";
            exit(2);
        }   //end inner if/else  
    } 	//end outer if 
}//end undoLastChange

void editor::writeToFile()
{
    ofstream outfile;

    outfile.open(mTextFile);
    int numberOfLines = lines.getLength();
    //Loop to write each line to the output file.
    for (int i = 1; i < numberOfLines + 1; i++)
    {
        outfile << lines.getEntry(i);
        outfile << endl;
    }

    outfile.close();
}

//Page 5

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
            getline(cin >> ws, nextCommand);

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
    
    //Variables involved in pushing data onto stackOfChanges
    int currentLineNumber = 1;
    string toBeDeleted = "";
    string currentLine = "";
    string currentChar = "";
    int indexInString = 0;
    bool success = true;

    //Compiler does not allow instantiation of object inside a switch case.
    //Instantiate object with placeholder values to be replaced by real data.
    Change newDeletion;

    //Loop to process commands entered by user.
    while (!endProgram)
    {
        command = _getch();

        //Switch to execute the appropriate code depending on command entered.
        switch (command)
        {
        case 'x':
            //Case to delete current character.

            //Get data needed for Change object
            currentLineNumber = (userPosition.getY() + 1); //Y coordinates start at 0, Lines start at 1
            indexInString = userPosition.getX();    //x-coordinates and string indices both start at 0;
            currentChar = lines.getEntry(currentLineNumber);
            toBeDeleted = currentChar;
           
            //Place data into Change object
            newDeletion.setPositionOfDeletedContents(userPosition);
            newDeletion.setChangedCharacters(toBeDeleted);
            newDeletion.setCommand(command);
            newDeletion.setLineNumber(currentLineNumber);
//Page 6             
            //Push Change object onto stack to save data for the undo feature.
            success = stackOfChanges.push(newDeletion);

            if (!success)
            {
                cerr << "\n\nError. Push to stack failed. Goodbye!\n\n";
                exit(2);
            }

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
                //Get data needed for Change Object
                currentLineNumber = (userPosition.getY() + 1); //Y coordinates start at 0, Lines start at 1
                currentLine = lines.getEntry(currentLineNumber);
                indexInString = userPosition.getX();    //x-coordinates and string indices both start at 0;
                toBeDeleted = currentLine;

                //Send data to Change object

                newDeletion.setPositionOfDeletedContents(userPosition);
                newDeletion.setChangedCharacters(toBeDeleted);
                newDeletion.setCommand(command);
                newDeletion.setLineNumber(currentLineNumber);

                //Push Change object onto stack to save data for the undo feature.
                success = stackOfChanges.push(newDeletion);

                if (!success)
                {
                    cerr << "\n\nError. Push to stack failed. Goodbye!\n\n";
                    exit(2);
                }

                deleteCurrentLine();
                changesWereMadeButNotSaved = true;
                displayLines(); //Allows user to see change in real time.

            }
            //else do nothing.
            break;
        case 'u':
            undoLastChange();
            displayLines();
            break;
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

void editor::fillKeywordTree()
{
    string nextKeyword = "";
    ifstream infile;
    infile.open(mKeywordFile);

    if (infile.fail())
    {
        cerr << "Error. Unable to open file \"" << mKeywordFile << "\".\n\nGoodbye!\n\n";
        exit(2);
    }

    //Loop to read keywords from file into binary search tree keywordTree.
    while ( !infile.eof() )
    {
        infile >> nextKeyword;
        keywordTree.add(nextKeyword);
    }

    infile.close();
}