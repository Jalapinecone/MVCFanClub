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
        if (words.size() != 3) {
        std::cout << "Could not compile comp statement. Requires 2 operands to compile";
        exit(1);
    }
    operands.push_back(new operand(std::string(words[1])));
	operands.push_back(new operand(std::string(words[2])));

}

void compstmt::run(){

}

vector<char*> compstmt::split(string inst){
        vector<char*> words;
        char *start = &inst[0];
        for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
        }
        return words;
}

