#include<iostream>
#include "editor.h"

using namespace std;
int main() {

	//	cout << "test";
	//	string name;
	//	cout << "Enter the name of your file" << endl;
	//	cin >> name;
	editor vi{ "test.txt" };
//	vi.displayLines();
	vi.run();


	return 0;
}