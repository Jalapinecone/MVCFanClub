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
        char* labl = words[0];
        if(labl[(strlen(labl) - 1)] == ':'){
                label* lb = new label(std::string(words[0]));
                addLabel(lb);
                setInstruction(string(words[1]));
                operand* op = new operand(std::string(words[2]));
                addOperand(op);
        }
        else{
                setInstruction(string(words[0]));
                if (words.size() != 2) {
                        std::cout << "Could not compile prt statement. Requires 1 operand to compile";
                        exit(1);
                }
                operand* op = new operand(std::string(words[1]));
                addOperand(op);
	}

}

void printstmt::run(){

}
vector<char *> printstmt::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];
	char *character = strtok(str," ");
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}


