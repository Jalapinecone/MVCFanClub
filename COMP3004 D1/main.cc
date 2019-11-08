#include <iostream>
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
	int adminSel;
       	bool isAdmin = false;	
	cout << "Are you an admin?" << endl;
	cout << "(0) Yes (1) No" << endl;
	cin >> adminSel;
	if(adminSel == 0){
		isAdmin = true;
	}
	program currentProgram;
        functionInterface defaultInt;
        createProgram CreateProgram;
        saveProgram SaveProgram;
        loadProgram LoadProgram;
    	runProgram RunProgram;
	editProgram EditProgram;
	compileProgram CompileProgram;
	manageSystemPrefs ManageSystemPrefs;
    	SCAPESmain SCAPESMainObj;
        int selection;
        cout << endl;
        cout << "(0) CreateProgram" << endl;
        cout << "(1) SaveProgram" << endl;
        cout << "(2) LoadProgram" << endl;
	cout << "(3) RunProgram" << endl;
        cout << "(4) EditProgram" << endl;
        cout << "(5) CompileProgram" << endl;
	if(isAdmin){
		cout << "(6) ManageSysPref" << endl;
	}
	cout << "Enter your selection: ";
        cin >> selection;
        if(selection == 0){
                cout << "CREATE PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&CreateProgram);
                SCAPESMainObj.execute();
        }
        else if(selection == 1){
                cout << "SAVE PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&SaveProgram);
                SCAPESMainObj.execute();
        }
        else if(selection == 2){
                cout << "LOAD PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&LoadProgram);
                SCAPESMainObj.execute();
        }
	else if(selection == 3){
                cout << "RUN PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&RunProgram);
                SCAPESMainObj.execute();
        }
        else if(selection == 4){
                cout << "EDIT PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&EditProgram);
                SCAPESMainObj.execute();
        }
	else if(selection == 5){
                cout << "COMPILE PROGRAM" << endl;
                SCAPESMainObj.setFunctionInterface(&CompileProgram);
                SCAPESMainObj.execute();
        }
        else if(selection == 6){
                cout << "MANAGE SYSTEM PREFERENCES" << endl;
                SCAPESMainObj.setFunctionInterface(&ManageSystemPrefs);
                SCAPESMainObj.execute();
        }


}
