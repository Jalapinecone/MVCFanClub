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

//Creates a vector storing each part of a statement: labels and instructions
void endstmt::compile(string inst){
	vector<char*> words = split(inst);
        char* labl = words[0];
		// Check to see if there is a label
        if(labl[(strlen(labl) - 1)] == ':'){
				//create label, and instruction objects
                label* lb = new label(std::string(words[0]));
                addLabel(lb);
                setInstruction(string(words[1]));
	}
	else{
		//Create instruction object
		setInstruction(string(words[0]));

	}	
}

//Not used for D1
void endstmt::run(){

}

