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

void statement::setInstruction(string instr){
	instruction = instr;
}

void statement::addOperand(operand* op){
	operands.push_back(op);
}
void statement::addLabel(label* lbl){
	labels.push_back(lbl);
}
vector<operand*> statement::getOperands()
{
	return operands;
}
vector<label*> statement::getLabels(){
	return labels;
}
