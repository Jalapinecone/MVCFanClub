#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "endStmt.h"

endstmt::endstmt(string inst){

	instructions = inst;
	compile(inst);
}

endstmt::~endstmt(){

}

void endstmt::compile(string inst){
	vector<char*> words = split(inst);
        if (words.size() != 1) {
        std::cout << "Could not compile end statement. It should have no operands.";
	exit(1);
    }	
}

void endstmt::run(){

}
vector<char*> endstmt::split(string inst){
        vector<char*> words;
        char *start = &inst[0];
        for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
        }
        return words;
}

