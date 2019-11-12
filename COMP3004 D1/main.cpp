/*-----------------------------
    SCAPES system Deliverable 1
    November 12, 2019
    The MVC Fan Club 
    By:
        Alex Cornish (101053176)
        Brad Campbell (101070833)
        Jared Sherwood (101035878)
        Ryan Ayotte (101073548)
-----------------------------*/
#include <iostream>
#include <vector>
#include <QApplication>
#include <QPushButton>
#include "window.h"
#include <string>

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

//Launches the main program, Qt application, and the interface
int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Window window;
 window.show();


 return app.exec();

}
