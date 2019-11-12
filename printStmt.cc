#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "printStmt.h"

//Sets the internal instruction string to the passed in string
printstmt::printstmt(string inst){

	instructions = inst;
	compile(inst);
}

printstmt::~printstmt(){

}

//Creates a vector storing each part of a statement: label, instructions and operands
void printstmt::compile(string inst){
	vector<char*> words = split(inst);
        char* labl = words[0];
		//Check to see if label was inputted
        if(labl[(strlen(labl) - 1)] == ':'){
			//Create label, instruction, and operand objects
                label* lb = new label(std::string(words[0]));
                addLabel(lb);
                setInstruction(string(words[1]));
                operand* op = new operand(std::string(words[2]));
                addOperand(op);
        }
        else{
				//Create instruction and operand objects
                setInstruction(string(words[0]));
				//Ensuring Enough operands were entered for the printStmt instruction
                operand* op = new operand(std::string(words[1]));
                addOperand(op);
	}

}

//Not used for D1
void printstmt::run(){

}
