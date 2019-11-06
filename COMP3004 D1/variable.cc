#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "variable.h"

variable::variable(int num) : identifier(name)
{
	value = num;
}

variable::~variable(){

}

int variable::getValue(){
	return value;
}
