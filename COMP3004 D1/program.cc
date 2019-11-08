#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "program.h"

program::program(){

}
program::program(string inputStr)
{
        filename = inputStr;
}

program::~program(){

}

void program::compile(){
        cout << "compile program" << endl;
}

void program::execute(){
        cout << "run program" << endl;
}
void program::print(){
	cout << "print program" << endl;
}
