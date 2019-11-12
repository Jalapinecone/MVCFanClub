#include "windowInterface.h"
using namespace std;

WindowInterface::WindowInterface(){

}

void WindowInterface::createProg(){
  SCAPESMainObj.setFunctionInterface(&CreateProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::saveProg(){
  SCAPESMainObj.setFunctionInterface(&SaveProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::loadProg(){
  SCAPESMainObj.setFunctionInterface(&LoadProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::runProg(){
  SCAPESMainObj.setFunctionInterface(&RunProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::compileProg(){
  SCAPESMainObj.setFunctionInterface(&CompileProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::managePrefs(){
  SCAPESMainObj.setFunctionInterface(&ManageSystemPrefs);
  SCAPESMainObj.execute(currentProgram);
}
