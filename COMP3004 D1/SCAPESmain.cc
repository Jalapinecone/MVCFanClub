#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "SCAPESmain.h"
#include "functionInterface.h"
#include "createProgram.h"
#include "saveProgram.h"

//Main interface class - member functions for all classes inheriting from it
//Sets the internal current interface to the passed in one
void SCAPESmain::setFunctionInterface(functionInterface* funInt)
{
	_funInt = funInt;
}

void SCAPESmain::execute(program &p){
	_funInt->execute(p);
}
