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

//Abstract compiler
void statement::compile(string instr){
	cout << "compile program" << endl;
}

//Not used for D1
void statement::run(){
	cout << "run program" << endl;
}

//Getter function for geting the current statements instructions 
string statement::getInstruction(){
	return instruction;
}

//Setter function for setting the current statements instructions
void statement::setInstruction(string instr){
	instruction = instr;
}

//Adds operand to the statement
void statement::addOperand(operand* op){
	operands.push_back(op);
}

//Adds label to the statement
void statement::addLabel(label* lbl){
	labels.push_back(lbl);
}

//Getter function for geting the current statements operands
vector<operand*> statement::getOperands()
{
	return operands;
}

//Getter function for geting the current statements labels
vector<label*> statement::getLabels(){
	return labels;
}
