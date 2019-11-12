#include "windowInterface.h"
using namespace std;

WindowInterface::WindowInterface(){

}

void WindowInterface::createProg(string newProgName){
  currentProgram.filename = newProgName;
  SCAPESMainObj.setFunctionInterface(&CreateProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::saveProg(string saveProgName, vector<string> saveProgLines){
  currentProgram.filename = saveProgName;
  currentProgram.lines = saveProgLines;
  SCAPESMainObj.setFunctionInterface(&SaveProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::loadProg(string loadProgName){
  currentProgram.filename = loadProgName;
  SCAPESMainObj.setFunctionInterface(&LoadProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::runProg(){
  SCAPESMainObj.setFunctionInterface(&RunProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::compileProg(string compProgName, vector<string> compProgLines){
  currentProgram.fileName = compProgName;
  currentProgram.lines = compProgLines;
  SCAPESMainObj.setFunctionInterface(&CompileProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::managePrefs(){
  SCAPESMainObj.setFunctionInterface(&ManageSystemPrefs);
  SCAPESMainObj.execute(currentProgram);
}
