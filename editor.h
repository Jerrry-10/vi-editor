#ifndef EDITOR_H_
#define EDITOR_H_

#include "LinkedList.h"

#include<fstream>
#include<string>
#include<memory>
using namespace std;

class editor {

private:
	LinkedList<string> lines;
public:
	/** Default constructor
	@post  Instantiates an empty editor object.
	*/
	editor();
	
	/**Constructor which reads a file into the object it instantiates.
	@param file  The name of the file to be read into the editor object.
	@pre  file is is in same directory as project and can be opened.
	@post  Prints an error message if precondition is violated. Otherwise, each line of file
	is read into the new editor object. */
	editor(string file);
	void DisplayLines();
//	void run();
	

	/* Future methods
	void moveUp();
	void movedown();
	void moveleft();
	void moveright();
	void deleteChar();

	*/

};
#include "editor.cpp"
#endif 
