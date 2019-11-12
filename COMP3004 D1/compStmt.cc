#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "compStmt.h"

compstmt::compstmt(string inst){

	instructions = inst;
	compile(inst);
}

compstmt::~compstmt(){

}

void compstmt::compile(string inst){
	vector<char*> words = split(inst);
        char* labl = words[0];
        if (labl[(strlen(labl) - 1)] == ':') {
		label* lb = new label(std::string(words[0]));
		addLabel(lb);
		setInstruction(string(words[1]));
		operand* op = new operand(std::string(words[2]));
		addOperand(op);
		operand* op2 = new operand(std::string(words[3]));
		addOperand(op2);
	}
	else{
        	if (words.size() != 3) {
        	std::cout << "Could not compile comp statement. Requires 2 operands to compile";
        	exit(1);
    		}
		setInstruction(string(words[0]));
                operand* op = new operand(std::string(words[1]));
                addOperand(op);
                operand* op2 = new operand(std::string(words[2]));
                addOperand(op2);
	}

}

void compstmt::run(){

}

vector<char *> compstmt::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];
	char *character = strtok(str," ");
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}

