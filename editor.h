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
	LinkedList<string> lines;
	
	/** Helper function to write contents of Editor object to output file.
	@post  Contents written to file "test.txt" */
	void writeToFile();
	
	/**Helper function to delete the character at the user's current position.
	@param userPosition  The current position of the user's cursor in the editor.
	@post  The character at the userPosition has been deleted. */
	void deleteCurrentCharacter(Position userPosition);
	
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
	void displayLines();
	//	void run();


		/* Future methods
		void moveUp();
		void movedown();
		void moveleft();
		void moveright();
		void deleteChar();
		*/

};

#endif 
