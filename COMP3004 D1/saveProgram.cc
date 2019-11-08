#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "saveProgram.h"
//Changes made to main.cc, saveProgram.h, saveProgram.cc, SCAPESmain.cc, SCAPESmain.h, functionInterface.h, functionInterface.cc
void saveProgram::execute(vector<string> &v)
{
        cout << "Enter name of file: ";
        cin >> fileName;
        cout<<endl;
        fileName += ".txt";

        std::ofstream saveFile;
        saveFile.open(fileName);

        for(string n: v)
        {
                saveFile << n << endl;
        }
        saveFile << text;

        saveFile.close();
}
