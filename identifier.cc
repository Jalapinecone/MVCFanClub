#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "identifier.h"

//Member functions for all classes inheriting from this class
identifier::identifier()
{
	
}
identifier::identifier(string n)
{
    cout << "Create identifier and set name" << endl;
	name = n;
}
identifier::~identifier(){

}

//Getter function
string identifier::getName(){
	return name;
}
