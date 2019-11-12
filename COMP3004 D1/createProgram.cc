#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std; 

#include "createProgram.h"

//Creates a new program attached to the passed program object
void createProgram::execute(program &p)
{

	//Creates new program object
	program* newProgram = new program;
	newProgram->changeName(p.filename);
	//Re-prints the program's name
	p = *newProgram;
	//checks to see if the file exists already
	std::ifstream fileExist(p.filename+".txt");
	if(!fileExist){
		//If the file doesn't exist, create it
		p.errors.insert(p.errors.begin(), "File Created with name: " + p.filename);
                std::ofstream file {p.filename+".txt"};
                file.close(); //close the file
	}
	else{
		//If the file exists tell the user that it will overwrite
               p.errors.insert(p.errors.begin(), "File Already exists with name: " + p.filename + " if you click save you will overwrite this file");

	}
	fileExist.close(); //close the file
	delete(newProgram);
}
createProgram::createProgram()
{	
}

createProgram::~createProgram()
{
}
