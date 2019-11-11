#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#include "declIntStmt.h"

declintstmt::declintstmt(string inst){
	instructions = inst;
	compile(inst);
}

declintstmt::~declintstmt(){

}

void declintstmt::compile(string inst){
	vector<char*> word = split(inst);
	if (word.size() != 2) {
        std::cout << "Could not compile dci statement. Requires 1 operand to compile";
        exit(1);
    }
    operands.push_back(new operand(std::string(word[1])));
}

void declintstmt::run(){

}

vector<char*> declintstmt::split(string inst){
	vector<char*> word;
        char *start = &inst[0];
        for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        word.push_back(start);
        }
	return word;
}

