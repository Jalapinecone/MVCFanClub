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

//Creates a vector storing each part of a statement: instructions and operands
void declintstmt::compile(string inst){
	vector<char*> words = split(inst);
	instruction = string(words[0]);

	//Ensuring Enough operands were entered for the declint instruction
	if (words.size() != 2) {

        std::cout << "Could not compile dci statement. Requires 1 operand to compile";
        exit(1);
    }
	//Stores the operands into a vector attached to the compstmt object
    operands.push_back(new operand(std::string(words[1])));
}

//Not used for D1
void declintstmt::run(){

}

