#ifndef EDITOR_H_
#define EDITOR_H_

#include "LinkedList.h"
#include "position.h"
#include<windows.h>
#include<fstream>
#include<string>
#include<memory>
using namespace std;

class editor {

private:
	LinkedList<string> lines;
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
#include"editor.cpp"
#endif 