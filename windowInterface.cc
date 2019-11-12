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
//mostly works but it crashes if it doesn't find a program so it's not ready for deployment
std::string WindowInterface::loadProg(string loadProgName){
  currentProgram.filename = loadProgName;
  SCAPESMainObj.setFunctionInterface(&LoadProgram);
  SCAPESMainObj.execute(currentProgram);
  return LinesToString(currentProgram.lines);
}
//interface with the main program to configure the compilation and feed the lines of code down.
std::string WindowInterface::compileProg(string compProgName, string inCode){
  currentProgram.filename = compProgName;
  currentProgram.lines = toLines(inCode);
  SCAPESMainObj.setFunctionInterface(&CompileProgram);
  SCAPESMainObj.execute(currentProgram);
  return LinesToString(currentProgram.errors);
}
//not yet implemented
void WindowInterface::runProg(){
  SCAPESMainObj.setFunctionInterface(&RunProgram);
  SCAPESMainObj.execute(currentProgram);
}
//not yet implemented
void WindowInterface::managePrefs(){
  SCAPESMainObj.setFunctionInterface(&ManageSystemPrefs);
  SCAPESMainObj.execute(currentProgram);
}
//convert a string into a vector of strings by line breaks.
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
//convert a vector of strings into a solid string with each entry in the vector being separated by line breaks
std::string WindowInterface::LinesToString(std::vector<string> v){
  string accumulator = "";
  for(unsigned i = 0; i < v.size(); i++){
    accumulator += v.at(i) + '\n';
  }
  return accumulator;
}
