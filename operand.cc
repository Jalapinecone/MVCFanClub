#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "operand.h"

//Sets the internal operand string to the passed string
operand::operand(string op)
{
        eachOperand = op;
}
operand::~operand(){

}

//Getter function for getting the name of the operand
string operand::getName(){
	return eachOperand;
}
