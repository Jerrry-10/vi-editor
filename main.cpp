#include<iostream>
#include "editor.h"

using namespace std;
int main() {

//	cout << "test";
//	string name;
//	cout << "Enter the name of your file" << endl;
//	cin >> name;
	editor vi{ "test.txt" };
	vi.DisplayLines();
	// run();


	return 0;
}
