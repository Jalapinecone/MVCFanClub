#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

#include "createProgram.h"

void createProgram::execute(program &p)
{
	cout << "---------------------------" << endl;
	cout << "Create program code" << endl;
	cout << p.filename << endl;
	program* newProgram = new program;
	string newProgramTitle; 
	cout << "New Program Name: ";
	cin >> newProgramTitle;
	newProgram->changeName(newProgramTitle);
	cout << "File name:" << newProgram->filename << endl;
	p = *newProgram;
	cout << p.filename << endl;
}
createProgram::createProgram()
{
		
}
