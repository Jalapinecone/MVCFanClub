#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "loadProgram.h"

void loadProgram::execute(vector<string> &code)
{
        cout << "Enter name of file: ";
        cin >> fileName;
        cout<<endl;
        fileName += ".txt";

        std::ifstream file;
        file.open (fileName);
          
        while (file.good()){
             getline(file, text);
             code.push_back(text);
        }
        cout << endl;
          
    file.close();

    cout<< "\nFile Loaded Successfully!\n"<<endl;
}
loadProgram::loadProgram()
{
}
