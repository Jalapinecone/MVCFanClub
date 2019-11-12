#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "label.h"


label::label() : identifier(name)
{

}

//Sets internal identifier name to the passed name string
label::label(string n)
{
    name = n;
}
label::~label(){

}

//Basic getter to get the name 
string label::getName(){
	return name;
}
