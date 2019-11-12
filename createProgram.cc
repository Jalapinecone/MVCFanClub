#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "createProgram.h"

void createProgram::execute(program &p)
{
	program* newProgram = new program;
	newProgram->changeName(p.filename);
	cout << "File name:" << newProgram->filename << endl;
	p = *newProgram;
	cout << p.filename << endl;
}
createProgram::createProgram()
{

}
