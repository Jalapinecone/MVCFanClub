#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "saveProgram.h"
//Changes made to main.cc, saveProgram.h, saveProgram.cc, SCAPESmain.cc, SCAPESmain.h, functionInterface.h, functionInterface.cc
void saveProgram::execute(vector<string> &code)
{
        cout << "Enter name of file: ";
        cin >> fileName;
        cout<<endl;
        fileName += ".txt";

        std::ofstream file;
        file.open(fileName);

        for(string n: code)
        {
                file << n << endl;
        }
        file << text;

        file.close();

        cout<< "\nFile Saved Successfully!\n"<<endl;
}
