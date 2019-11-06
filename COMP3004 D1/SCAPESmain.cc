#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "SCAPESmain.h"
#include "functionInterface.h"
#include "createProgram.h"
#include "saveProgram.h"

void SCAPESmain::setFunctionInterface(functionInterface* funInt)
{
	_funInt = funInt; 
}

void SCAPESmain::execute(){ 
	_funInt->execute();
}
