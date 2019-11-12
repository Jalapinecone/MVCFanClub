#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

#include "createProgram.h"

//Creates a new program attached to the passed program object
void createProgram::execute(program &p)
{

	//Creates new program object
	program* newProgram = new program;
	newProgram->changeName(p.filename);
	cout << "File name:" << newProgram->filename << endl;

	//Re-prints the program's name
	p = *newProgram;
	cout << p.filename << endl;
}
createProgram::createProgram()
{
		
}
