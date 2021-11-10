/**@file  editor.h Page 1
Class to create and run a primitive text editor.
@author Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 8, 2021
*/
#ifndef EDITOR_H_
#define EDITOR_H_

#include "LinkedList.h"
#include "position.h"
#include<windows.h>
#include<fstream>
#include<string>
#include<memory>
#include<conio.h>
using namespace std;

class editor {

private:
	LinkedList<string> lines; //A list of lines of text.
	Position userPosition;
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
	@post  Instantiates empty Editor object.
	*/
	editor();

	/** Constructor which instantiates an Editor object by reading a text file into it.
	@param file  The name of the file to be read in.
	@pre  The string file denotes a valid text file in the same directory as the project.
	@post  Prints error message and terminates program if file cannot be opened.
		Otherwise, each line in file becomes an item in the list lines. */
	editor(string file);
	
	/**Function to print the contents of the LinkedList lines to the screen.
	@post  Each entry in lines is printed to the screen on its own line. */
	void displayLines();
	
	/**Function to read in user's commands as single characters and execute them.
	@post  User's commands have been executed. */
	void run();


		/* Future methods
		void moveUp();
		void movedown();
		void moveleft();
		void moveright();
		void deleteChar();
		*/

};

#endif 
