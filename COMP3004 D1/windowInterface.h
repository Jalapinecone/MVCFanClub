//Created by Jared
//This class serves to replace all the command line logic in the main.cc and interface with the window class
#ifndef WINDOW_INTERFACE
#define WINDOW_INTERFACE

#include <iostream>
#include <vector>
#include <sstream>
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

class WindowInterface{
public:
  WindowInterface();
  string createProg(string newProgName);
  string saveProg(std::string saveProgName, std::string inCode);
  string loadProg(string loadProgName);
  void runProg();
  string compileProg(string compProgName, string compProgLines);
  void managePrefs();

private:
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

  std::vector<std::string> toLines(std::string s);
  std::string LinesToString(std::vector<string> v);

};
#endif
