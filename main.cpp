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

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Window window;
 window.show();


 return app.exec();

}
