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

		//Ensuring Enough operands were entered for the compStmt instruction
        if (words.size() != 3) {
        std::cout << "Could not compile comp statement. Requires 2 operands to compile";
        exit(1);
    }

	//Stores the operands into a vector attached to the compstmt object
    operands.push_back(new operand(std::string(words[1])));
    operands.push_back(new operand(std::string(words[2])));

}

//Not used for D1
void compstmt::run(){

}

