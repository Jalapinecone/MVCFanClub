#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "saveProgram.h"

//Function used to load in a text file containing the un-compiled code
//strings are stored in a vectored and saved one by one into a text file
void saveProgram::execute(program &p)

{
	cout << "SAVE" << endl;

        //Ask user for file name and stores it
	string fileName;
	cout << "Enter name of file: ";
        cin >> fileName;
        cout<<endl;

        //Adds the .txt extension to the file
        fileName += ".txt";
	cout << fileName << endl;

        //Opens/creates the file for editing
        std::ofstream file;
        file.open(fileName);

        //Loops through the lines vector and stores each to the file
        for(string n: p.lines)
        {
                file << n << endl;
        }

        file.close();

        cout<< "\nFile Saved Successfully as " << fileName << "\n"<<endl;
}
