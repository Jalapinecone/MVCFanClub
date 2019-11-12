#include "windowInterface.h"
using namespace std;

WindowInterface::WindowInterface(){

}

void WindowInterface::createProg(string newProgName){
  currentProgram.filename = newProgName;
  SCAPESMainObj.setFunctionInterface(&CreateProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::saveProg(string saveProgName, string inCode){
  currentProgram.filename = saveProgName;
  currentProgram.lines = toLines(inCode);
  SCAPESMainObj.setFunctionInterface(&SaveProgram);
  SCAPESMainObj.execute(currentProgram);
}

vector<string> WindowInterface::loadProg(string loadProgName){
  currentProgram.filename = loadProgName;
  SCAPESMainObj.setFunctionInterface(&LoadProgram);
  SCAPESMainObj.execute(currentProgram);
  cout << currentProgram.lines.at(0);
  return currentProgram.lines;
}

void WindowInterface::compileProg(string compProgName, string inCode){
  currentProgram.filename = compProgName;
  currentProgram.lines = toLines(inCode);
  SCAPESMainObj.setFunctionInterface(&CompileProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::runProg(){
  SCAPESMainObj.setFunctionInterface(&RunProgram);
  SCAPESMainObj.execute(currentProgram);
}

void WindowInterface::managePrefs(){
  SCAPESMainObj.setFunctionInterface(&ManageSystemPrefs);
  SCAPESMainObj.execute(currentProgram);
}

std::vector<std::string> WindowInterface::toLines(std::string s){
  vector<string> lines;

  char *str =  &s[0];
  std::stringstream ss(str);
  std::string to;

  if (str != NULL){
    while(std::getline(ss,to,'\n')){
      lines.push_back(std::string(to));
    }
  }
  return lines;
}
