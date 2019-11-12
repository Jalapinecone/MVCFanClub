#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "variable.h"

//Sets the current value to the passed in one for a given identifier
variable::variable(int num) : identifier(name)
{
	value = num;
}

variable::variable(string n)
{
	name = n;
}

variable::~variable(){

}

//Getter function for retreicing the current variable value
int variable::getValue(){
	return value;
}
