#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "loadProgram.h"


//Function used to load in a text file containing the un-compiled code
//Loaded program is saved to a vector member of the passed program object
void loadProgram::execute(program &p)
{
	//Gets file name from the user, storing it to a string
	string fileName;
	cout << "Enter name of file: ";
	cin >> fileName;
	cout << endl;

	//Adds the .txt extension to the file
	fileName += ".txt";
	cout << fileName << endl;

	//opens the file for writing
	std::ifstream file;
	file.open(fileName);

	p.filename = fileName;
	p.lines = {};

	//Loops through the file and saves each line to the lines vector
	while (file.good()) {
		getline(file, text);
		p.lines.push_back(text);
	}
	cout << endl;

	file.close();

	cout << "\nFile Loaded Successfully!\n" << endl;
}
loadProgram::loadProgram()
{
}

