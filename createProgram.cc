#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

#include "createProgram.h"

//Creates a new program attached to the passed program object
void createProgram::execute(program &p)
{
	cout << "---------------------------" << endl;
	cout << "Create program code" << endl;
	cout << p.filename << endl;

	//Creates new program object
	program* newProgram = new program;
	string newProgramTitle; 

	//Asks the user for a program name and sets it to the program's title
	cout << "New Program Name: ";
	cin >> newProgramTitle;
	newProgram->changeName(newProgramTitle);
	cout << "File name:" << newProgram->filename << endl;

	//Re-prints the program's name
	p = *newProgram;
	cout << p.filename << endl;
}
createProgram::createProgram()
{
		
}
