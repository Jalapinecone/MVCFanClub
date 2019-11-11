#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "saveProgram.h"
//Changes made to main.cc, saveProgram.h, saveProgram.cc, SCAPESmain.cc, SCAPESmain.h, functionInterface.h, functionInterface.cc
void saveProgram::execute(program &p)

{
	string fileName;
	cout << "Enter name of file with .txt extension: ";
        cin >> fileName;
        cout<<endl;

        std::ofstream file;
        file.open(fileName);

        for(string n: p.lines)
        {
                file << n << endl;
        }
	cout << text << endl;
        file << text;

        file.close();

        cout<< "\nFile Saved Successfully as " << fileName << "\n"<<endl;
}
