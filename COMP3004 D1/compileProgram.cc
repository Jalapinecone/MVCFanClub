#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "compileProgram.h"

void compileProgram::execute(program &p)
{
	cout << "COMPILE" << endl;
        p.compile();
}
compileProgram::compileProgram()
{
}

