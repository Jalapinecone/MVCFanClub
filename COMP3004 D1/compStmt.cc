#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "compStmt.h"

//Sets the internal instruction string to the passed in string
compstmt::compstmt(string inst){

	instructions = inst;
	compile(inst);
}

compstmt::~compstmt(){

}

//Creates a vector storing each part of a statement: instructions and operands
void compstmt::compile(string inst){
	vector<char*> words = split(inst);
    char* labl = words[0];
	//Check to see if there is a label
    if (labl[(strlen(labl) - 1)] == ':') {
		//Ensuring Enough operands were entered for the compStmt instruction
		if (words.size() != 4) {
			cout << "Could not compile comp statement. Requires 2 operands to compile";
			exit(1);
		}
		//Create Label, Operands, and Instruction objects
		label* lb = new label(std::string(words[0]));
		addLabel(lb);
		setInstruction(string(words[1]));
		operand* op = new operand(std::string(words[2]));
		addOperand(op);
		operand* op2 = new operand(std::string(words[3]));
		addOperand(op2);
	}
	else{
		//Ensuring Enough operands were entered for the compStmt instruction
        if (words.size() != 3) {
        	std::cout << "Could not compile comp statement. Requires 2 operands to compile";
        	exit(1);
    		}
		//Create Instruction, and Operands
		setInstruction(string(words[0]));
        operand* op = new operand(std::string(words[1]));
        addOperand(op);
        operand* op2 = new operand(std::string(words[2]));
        addOperand(op2);
	}

}

//Not used for D1
void compstmt::run(){

}
