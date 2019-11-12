#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "saveProgram.h"
//Changes made to main.cc, saveProgram.h, saveProgram.cc, SCAPESmain.cc, SCAPESmain.h, functionInterface.h, functionInterface.cc
void saveProgram::execute(program &p){

	//this chunk of code adds the contents of p.lines (the lines of code) to the file
  std::ofstream file;
  file.open(p.filename);

  for(string n: p.lines)
  {
      file << n << endl;
  }
	cout << text << endl;
  file << text;
  file.close();	//close the file because we're good programmers

  cout<< "\nFile Saved Successfully as " << p.filename << "\n"<<endl;
}
