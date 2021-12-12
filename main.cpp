/** @file main.cpp Page 1
Program to run a primitive text editor.
Version 4: Changed implementation of coloring keywords. Now uses a binary search tree instead of an
	array and binary search function.
Input:
	File input: Text (strings) from a .txt file passed as argv [1], C++ keywords stored in the hard-coded file "keywords.txt".
	getch/getche: User commands in the form of single characters.
	cin: Check for override command to quit without saving.
Output:
	File output: The updated text in argv[1], if the user opts to save the changes. Output to same file as input file.
	cerr: Error message if program terminates because an input file will not open.
	cout: The text and any changes to it, as well as echoing user's end-of-file commands. Warning if user
	tries to quit without saving changes.
@author: Kevin Reid, Jerry Aviles, & Xhudita Istrefi
December 12, 2021
*/
#include<iostream>
#include "editor.h"

using namespace std;
int main(int argc,  char* argv[]) {
	system("CLS");
	//	cout << "test";
	//	string name;
	//	cout << "Enter the name of your file" << endl;
	//	cin >> name;
	editor vi{ argv[1], "keywords.txt" };
	//argv[1] holds the text file we are editing.
	
	vi.run();


	return 0;
}
