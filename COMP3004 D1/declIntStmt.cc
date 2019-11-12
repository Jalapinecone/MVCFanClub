#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#include "declIntStmt.h"

//Sets the internal instruction string to the passed in string
declintstmt::declintstmt(string inst){
	instructions = inst;
	compile(inst);
}

declintstmt::~declintstmt(){

}

//Creates a vector storing each part of a statement: labels, instructions and operands
void declintstmt::compile(string inst){
	vector<char*> words = split(inst);
	char* labl = words[0];
	if(labl[(strlen(labl) - 1)] == ':'){
		//Ensuring Enough operands were entered for the declint instruction
		if (words.size() != 3) {
			std::cout << "Could not compile dci statement. Requires 1 operand to compile";
			exit(1);
		}
		// Create label, instruction and operand objects
        label* lb = new label(std::string(words[0]));
        addLabel(lb);
        setInstruction(string(words[1]));
        operand* op = new operand(std::string(words[2]));
        addOperand(op);
	}
	else{
		//Ensuring Enough operands were entered for the declint instruction
		if (words.size() != 2) {
        	std::cout << "Could not compile dci statement. Requires 1 operand to compile";
        	exit(1);
    	}
		//Create instruction and operand object
		setInstruction(string(words[0]));
		operand* op = new operand(std::string(words[1]));
		addOperand(op);
	}
}

//Not used for D1
void declintstmt::run(){

}

