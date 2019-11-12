#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "label.h"

label::label() : identifier(name)
{

}

label::label(string n)
{
    name = n;
}
label::~label(){

}
