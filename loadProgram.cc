#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "loadProgram.h"

void loadProgram::execute(program &p)
{
        std::ifstream file;
        file.open (p.filename);
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
