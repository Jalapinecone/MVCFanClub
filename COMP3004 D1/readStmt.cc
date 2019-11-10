#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "readStmt.h"

readstmt::readstmt(string inst){

	instructions = inst;
	compile(inst);
}

readstmt::~readstmt(){

}

void readstmt::compile(string inst){
	vector<char*> words = split(inst);
        if (words.size() != 2) {
        std::cout << "Could not compile rdi statement. Requires 1 operand to compile";
        exit(1);
    	}
    	operands.push_back(new operand(std::string(words[1])));
	
}

void readstmt::run(){

}

vector<char*> readstmt::split(string inst){
        vector<char*> words;
        char *start = &inst[0];
        for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
        }
        return words;
}

