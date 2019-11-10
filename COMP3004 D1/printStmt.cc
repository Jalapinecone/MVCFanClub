#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "printStmt.h"

printstmt::printstmt(string inst){

	instructions = inst;
	compile(inst);
}

printstmt::~printstmt(){

}

void printstmt::compile(string inst){
	vector<char*> words = split(inst);
        if (words.size() != 2) {
        std::cout << "Could not compile prt statement. Requires 1 operand to compile";
        exit(1);
    }
    operands.push_back(new operand(std::string(words[1])));
}

void printstmt::run(){

}
vector<char*> printstmt::split(string inst){
        vector<char*> words;
        char *start = &inst[0];
        for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
        }
        return words;
}


