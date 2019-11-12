#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

#include "createProgram.h"

void createProgram::execute(program &p)
{
	cout << "Create program code" << endl;
	program* newProgram = new program;
	newProgram->changeName(p.filename);
	p = *newProgram;
}
createProgram::createProgram()
{
		
}
