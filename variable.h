#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "identifier.h"

//variable initializer - inherits from identifier class
class variable : public identifier
{
	public:
		variable(int num);
		variable(string n);
		~variable();
		int getValue();
	private:
		int value;
};
#endif
