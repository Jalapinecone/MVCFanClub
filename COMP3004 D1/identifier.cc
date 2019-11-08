#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "identifier.h"

identifier::identifier(string n)
{
        cout << "Create identifier and set name" << endl;
	name = n;
}
identifier::~identifier(){

}
string identifier::getName(){
	return name;
}
