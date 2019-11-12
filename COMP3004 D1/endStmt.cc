#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "endStmt.h"

//Sets the internal instruction string to the passed in string
endstmt::endstmt(string inst){

	instructions = inst;
	compile(inst);
}

endstmt::~endstmt(){

}

//Creates a vector storing each part of a statement: instructions and operands
void endstmt::compile(string inst){
	vector<char*> words = split(inst);

		//Ensuring Enough operands were entered for the endStmt instruction
        if (words.size() != 1) {
        std::cout << "Could not compile end statement. It should have no operands.";
	exit(1);
    }	
}

//Not used for D1
void endstmt::run(){

}

