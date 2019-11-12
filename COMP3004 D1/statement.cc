#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "statement.h"

statement::statement()
{
        cout << "Create statement" << endl;
}

statement::~statement(){

}

void statement::compile(string instr){
	cout << "compile program" << endl;
}

void statement::run(){
	cout << "run program" << endl;
}

string statement::getInstruction(){
	return instruction;
}

vector<operand*> statement::getOperands()
{
	return operands;
}
