/** @file main.cpp Page 1
Program to run a primitive text editor.
Version 2: Updated to enable user to move cursor through text and delete whole lines.
	This version also warns user if changes have not been saved before trying to quit.
Input:
	File input: Text (strings) from a .txt file
	getch/getche: User commands in the form of single characters.
	cin: Check for override command to quit without saving.
Output:
	File output: The updated text, if the user opts to save the changes. Output to same file as input file.
	cerr: Error message if program terminates because input file will not open.
	cout: The text and any changes to it, as well as echoing user's end-of-file commands. Warning if user
	tries to quit without saving changes.
@author: Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 16, 2021
*/
#include<iostream>
#include "editor.h"

using namespace std;
int main(int argc  char* argv[]) {

	//	cout << "test";
	//	string name;
	//	cout << "Enter the name of your file" << endl;
	//	cin >> name;
	editor vi{ "test.txt" };
	vi.run();


	return 0;
}
