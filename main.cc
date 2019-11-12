//NOT TO BE INCLUDED WITH THE FINAL BUILD
//USED FOR COMMANDLINE EDITOR ONLY, NOT UI
#include <iostream>
#include <vector>
using namespace std;

#include "functionInterface.h"
#include "SCAPESmain.h"
#include "createProgram.h"
#include "saveProgram.h"
#include "loadProgram.h"
#include "runProgram.h"
#include "editProgram.h"
#include "compileProgram.h"
#include "manageSystemPrefs.h"
#include "program.h"

int main()
{
	//Testing vector for saveProgram
	program currentProgram;
	currentProgram.filename = "Test File Name 1";
	//currentProgram.lines = {"dci a","dci c", "cmp a c"};
	currentProgram.lines = {"L1: dci a", "end #weeee", "dci b", "#weeee"};
	cout << currentProgram.filename << endl;
	std::vector<string> results ={};

	int adminSel;
	bool isAdmin = false;	
	cout << "Are you an admin?" << endl;
	cout << "(0) Yes (1) No" << endl;
	cin >> adminSel;
	if(adminSel == 0){
		isAdmin = true;
	}

    	functionInterface defaultInt;
    	createProgram CreateProgram;
    	saveProgram SaveProgram;
    	loadProgram LoadProgram;
    	runProgram RunProgram;
	editProgram EditProgram;
	compileProgram CompileProgram;
	manageSystemPrefs ManageSystemPrefs;

	SCAPESmain SCAPESMainObj;
	string selection;
	while(selection != "8"){
		cout << "____________________________" << endl;
		cout << "(0) View Loaded Program Info" << endl;
	        cout << "(1) CreateProgram" << endl;
      	  	cout << "(2) SaveProgram" << endl;
        	cout << "(3) LoadProgram" << endl;
        	cout << "(4) RunProgram" << endl;
        	cout << "(5) EditProgram" << endl;
        	cout << "(6) CompileProgram" << endl;
        	if(isAdmin){
                	cout << "(7) ManageSysPref" << endl;
        	}
        	cout << "(8) Exit" << endl;

		cout << "Enter your selection: ";
        	cin >> selection;
		if(selection == "0"){
			cout << "CURRENT PROGRAM" << endl;
			cout << currentProgram.filename << endl;
			cout << "__________CURRENT_PROGRAM_LINES________" << endl;
			for(unsigned i = 0; i < currentProgram.lines.size(); i++){
				cout << currentProgram.lines[i] << endl;
			}
			cout << "_______________________________________" << endl;
		}
		else if(selection == "1"){
			cout << "CREATE PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&CreateProgram);
			SCAPESMainObj.execute(currentProgram);
		}
		else if(selection == "2"){
			cout << "SAVE PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&SaveProgram);
			SCAPESMainObj.execute(currentProgram);
		}
		else if(selection == "3"){
			cout << "LOAD PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&LoadProgram);
			SCAPESMainObj.execute(currentProgram);
		}
		else if(selection == "4"){
			cout << "RUN PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&RunProgram);
			SCAPESMainObj.execute(currentProgram);
    		}
		else if(selection == "5"){
			cout << "EDIT PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&EditProgram);
			SCAPESMainObj.execute(currentProgram);
		}
		else if(selection == "6"){
			cout << "COMPILE PROGRAM" << endl;
			SCAPESMainObj.setFunctionInterface(&CompileProgram);
			SCAPESMainObj.execute(currentProgram);
		}
		else if(selection == "7"){
			cout << "MANAGE SYSTEM PREFERENCES" << endl;
			SCAPESMainObj.setFunctionInterface(&ManageSystemPrefs);
			SCAPESMainObj.execute(currentProgram);
		}
	}
}
