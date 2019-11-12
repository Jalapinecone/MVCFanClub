#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#include "jumpStatement.h"

jumpstatement::jumpstatement(string inst){

        instructions = inst;
        compile(inst);
}

jumpstatement::~jumpstatement(){

}

void jumpstatement::compile(string inst){
	vector<char*> words = split(inst);
        if (words.size() != 2) {
        std::cout << "Could not compile jmp statement. Requires 1 operand to compile";
        exit(1);
    }
    operands.push_back(new operand(std::string(words[1])));
}

void jumpstatement::run(){

}

vector<char *> jumpstatement::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];
	char *character = strtok(str," ");
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}

