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
        cout << "compile program IN THE PROGRAM CLASS" << endl;
	for ( auto &i : lines ) {
		createStatement(stoi(i));
		//Statement* newStatement = statement.back();
		//newStatement->compile();
		//createIdentifier(newStatement, line);
	
	}
}

void program::execute(){
        cout << "run program" << endl;
}

void program::createStatement(int i){
	string line_no_comment = lines[i].substr(0, lines[i].find('#', 0));
	split(line_no_comment);
	char* label = words[0];  
	if(&label[(strlen(label)-1)] == ":"){
		identifiers.push_back(new identifier(string(words[0])));
	}
	else if(strcmp(words[0], "dci") == 0){
		//error check to make sure the variable doesn't already exist
		statements.push_back(new declintstmt(line_no_comment));
		identifiers.push_back(new identifier(string(words[1])));

	}
	else if(strcmp(words[0],"rdi") == 0){
		statements.push_back(new readstmt(line_no_comment));
	}
	else if(strcmp(words[0], "prt") == 0){
		statements.push_back(new printstmt(line_no_comment));
	}
	else if(strcmp(words[0], "cmp") == 0){
		statements.push_back(new compstmt(line_no_comment));
	}
	else if(strcmp(words[0], "jmr") == 0){
		statements.push_back(new jmorestmt(line_no_comment));
	}
	else if(strcmp(words[0], "jmp") == 0){
		//statements.push_back(new jumpstmt(line_no_comment));
	}
	else if(strcmp(words[0], "end") == 0){
		statements.push_back(new endstmt(line_no_comment));
	}
	else{
		std::cout << "Failed to compile: Invalid command found: " << words[0] << endl;

	}
}

void program::print(){
	cout << "print program" << endl;
}

void program::split(string line_no_comment){
	char *start = &line_no_comment[0];
	for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
	}
}
