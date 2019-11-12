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
	vector<char*> words = split(inst);
	instruction = string(words[0]);
	if (words.size() != 2) {

        std::cout << "Could not compile dci statement. Requires 1 operand to compile";
        exit(1);
    }
    operands.push_back(new operand(std::string(words[1])));
}

void declintstmt::run(){

}

vector<char *> declintstmt::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];
	char *character = strtok(str," ");
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}
