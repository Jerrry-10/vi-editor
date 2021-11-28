/**@file  editor.h Page 1
Class to create and run a primitive text editor.
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 16, 2021
*/
#ifndef EDITOR_H_
#define EDITOR_H_

#include "LinkedStack.h"
#include "LinkedList.h"
#include "position.h"
#include<windows.h>
#include<fstream>
#include<string>
#include "Change.h"
#include<memory>
#include<conio.h>
using namespace std;

class editor {

private:
	LinkedList<string> lines; //A list of lines of text.
	Position userPosition;
	bool changesWereMadeButNotSaved = false;
	bool endProgram = false;
	LinkedStack<Change> stackOfChanges;

	/** Helper function to write contents of Editor object to output file.
	@post  Contents written to file "test.txt" */
	void writeToFile();

	/**Helper function to delete the character at the user's current position.
	@param  userPosition  The current position of the user's cursor in the editor.
	@post  The character at userPosition has been deleted. */
	void deleteCurrentCharacter(Position userPosition);

	/**Helper function to read, echo, and execute user's end-of-program commands after ':'
	@post  User's final commands have been executed. Invalid commands have been ignored.
	@return  True if user has entered the command to quit the program and false otherwise. */
	bool endOfFileCommand();

public:
	/** Default Constructor.
	@post  Instantiates empty Editor object with no text.
	*/
	editor();

	/** Constructor which instantiates an Editor object by reading a text file into it.
	@param file  The name of the file to be read in.
	@pre  The string file denotes a valid text file in the same directory as the project.
	@post  Prints error message and terminates program if file cannot be opened.
		Otherwise, each line in file becomes an item in the list lines. */
	editor(string file);
	
	void colorText(int value);

	/**Function to undo the last change to the text.
	@post  The last change is undone. If no changes were made, does nothing.
	*/
	void undoLastChange();
	
	/**Function to print the contents of the LinkedList lines to the screen.
	@post  Each entry in lines is printed to the screen on its own line. */
	void displayLines();

	/**Function to read in user's commands as single characters and execute them.
	@post  User's commands have been executed. */
	void run();

	/**Method to move the cursor up one line.
	@post  Does nothing if cursor is already at top of file. Otherwise, moves cursor up one line. */
	void moveUp();

	/**Method to move the cursor down one line.
	@post  Does nothing if cursor is already at last line of file. Otherwise, moves cursor down one line. */
	void moveDown();

	/**Method to move the cursor left one space.
	@post  Does nothing if cursor is already at start of line. Otherwise, moves cursor one space to the left. */
	void moveLeft();

	/**Method to move the cursor right one space.
	@post  Does nothing if cursor is already on last character of line. Otherwise, moves the cursor right one space. */
	void moveRight();

	/**Method to delete the current line of text from the editor.
	@pre  cursor's position corresponds to a position on a valid line of text in the LinkedList lines.
	@post  current line of text has been deleted. */
	void deleteCurrentLine();



};

#endif 
