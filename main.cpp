/** @file main.cpp Page 1
Program to run a primitive text editor.
Input:
	File input: Text (strings) from a .txt file
	getch/getche: User commands in the form of single characters.
Output:
	File output: The updated text, if the user opts to save the changes. Output to same file as input file.
	cerr: Error message if program terminates because input file will not open.
	cout: The text and any changes to it, as well as echoing user's end-of-file commands.
@author: Kevin Reid, Jerry Aviles, & Xhudita Istrefi
November 8, 2021
*/
#include<iostream>
#include "editor.h"

using namespace std;
int main() {

	//	cout << "test";
	//	string name;
	//	cout << "Enter the name of your file" << endl;
	//	cin >> name;
	editor vi{ "test.txt" };
	run();


	return 0;
}
