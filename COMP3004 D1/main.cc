#include <iostream>
#include <vector>
using namespace std;

#include "functionInterface.h"
#include "SCAPESmain.h"
#include "createProgram.h"
#include "saveProgram.h"

int main()
{
	//Testing vector for saveProgram
	std::vector<string> lines = {"hello", "this", "is", "a", "trial"};

	functionInterface defaultInt;
	createProgram CreateProgram;
	saveProgram SaveProgram;

	SCAPESmain SCAPESMainObj;
	int selection;
	cout << endl;
	cout << "(0) CreateProgram" << endl;
	cout << "(1) SaveProgram" << endl;
	cout << "Enter your selection: ";
	cin >> selection;
	if(selection == 0){
                cout << "CREATE PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&CreateProgram);
                SCAPESMainObj.execute(lines);
	}
	else if(selection == 1){
			cout << "SAVE PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&SaveProgram);
			SCAPESMainObj.execute(lines);
	}

}
