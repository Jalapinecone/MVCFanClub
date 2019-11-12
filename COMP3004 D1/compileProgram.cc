#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "compileProgram.h"

void compileProgram::execute(program &p)
{
        p.compile();
	p.setCompare(false);
        p.setDone(false);
        p.setError(false);

}
compileProgram::compileProgram()
{
}

