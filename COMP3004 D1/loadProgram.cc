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
        cout << "Enter name of file: ";
        cin >> fileName;
        cout<<endl;
        fileName += ".txt";
	cout << fileName << endl;
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
