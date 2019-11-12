#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

#include "statement.h"

statement::statement()
{
        cout << "Create statement" << endl;
}

statement::~statement(){

}

void statement::compile(string instr){
	cout << "compile program" << endl;
}

void statement::run(){
	cout << "run program" << endl;
}

string statement::getInstruction(){
	return instruction;
}

//Getter function for geting the current statement;s operands
vector<operand*> statement::getOperands()
{
	return operands;
}

//Used to split up the instruction string into its different elements
vector<char *> statement::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];

	//This takes a vector of words, sending the characters to a string a vector until a "" is reached
	char *character = strtok(str," ");

	//Adds the words to a vector if they are not null
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}
