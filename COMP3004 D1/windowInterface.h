//Created by Jared on 10/11/2019
//This class serves to replace all the command line logic in the main.cc and interface with the window class
#ifndef WINDOW_INTERFACE
#define WINDOW_INTERFACE

#include <string>
#include <iostream>
#include <vector>
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
  void createProg(string);
  void saveProg(string, vector<string>);
  void loadProg(string);
  void runProg();
  void compileProg(string, vector<string>);
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

};
#endif
