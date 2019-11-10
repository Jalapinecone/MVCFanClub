#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#include "program.h"

program::program(){

}
void program::changeName(string inputStr)
{
        this->filename = inputStr;
	this->lines = {};
}

program::~program(){

}

void program::compile(){
        cout << "compile program" << endl;
	ifstream input(filename);
	string line;
	
	while(getline(input, line)){
		createStatement(line);
		//Statement* newStatement = statement.back();
		//newStatement->compile();
		//createIdentifier(newStatement, line);
	
	}
}

void program::execute(){
        cout << "run program" << endl;
}

void program::createStatement(string line){
	string line_no_comment = line.substr(0, line.find('#', 0));
	split(line_no_comment);
	char* label = words[0];  
	if(&label[(strlen(label)-1)] == ":"){
		identifiers.push_back(new identifier(string(words[0])));
	}
	else if(strcmp(words[0], "dci") == 0){
		statements.push_back(new declintstmt);
	}
	else if(strcmp(words[0],"rdi") == 0){
		statements.push_back(new readstmt);
	}
	else if(strcmp(words[0], "prt") == 0){
		statements.push_back(new printstmt);
	}
	else if(strcmp(words[0], "cmp") == 0){
		statements.push_back(new compstmt);
	}
	else if(strcmp(words[0], "jmr") == 0){
		statements.push_back(new jmorestmt);
	}
	else if(strcmp(words[0], "jmp") == 0){
	//	statements.push_back(new jumpstmt);
	}
	else if(strcmp(words[0], "end") == 0){
		statements.push_back(new endstmt);
	}
	else{
		std::cout << "Failed to compile: Invalid command found: " << words[0] << endl;

	}
}

void program::print(){
	cout << "print program" << endl;
}

vector<char*> program::split(string line_no_comment){
	//std::vector<char*> words;
	char *start = &line_no_comment[0];
	for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
	}
	return words;
}
