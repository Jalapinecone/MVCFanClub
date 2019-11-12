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

//Creates a vector storing each part of a statement: instructions and operands
void printstmt::compile(string inst){
	vector<char*> words = split(inst);

        //Ensuring Enough operands were entered for the printStmt instruction
        if (words.size() != 2) {
        std::cout << "Could not compile prt statement. Requires 1 operand to compile";
        exit(1);
    }

    //Stores the operands into a vector attached to the compstmt object
    operands.push_back(new operand(std::string(words[1])));
}

//Not used for D1
void printstmt::run(){

}