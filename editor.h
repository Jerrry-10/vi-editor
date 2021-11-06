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
	editor();
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
