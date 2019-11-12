#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "loadProgram.h"

void loadProgram::execute(program &p)
{
	string fileName;
        fileName = p.filename;
        fileName += ".txt";
        std::ifstream file;
        file.open (fileName);
        p.filename = fileName;
	p.lines = {};  
        while (file.good()){
             getline(file, text);
             p.lines.push_back(text);
        }
        cout << endl;
          
    file.close();

    cout<< "\nFile Loaded Successfully!\n"<<endl;
}
loadProgram::loadProgram()
{
}
