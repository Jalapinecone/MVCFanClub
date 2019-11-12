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
        char* labl = words[0];
        if(labl[(strlen(labl) - 1)] == ':'){
                label* lb = new label(std::string(words[0]));
                addLabel(lb);
                setInstruction(string(words[1]));
	}
	else{
		setInstruction(string(words[0]));
        	if (words.size() != 1) {
        	std::cout << "Could not compile end statement. It should have no operands.";
		exit(1);
    		}
	}	
}

void endstmt::run(){

}
vector<char *> endstmt::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];
	char *character = strtok(str," ");
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}

