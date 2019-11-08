#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
#include "statement.h"

class program
{
	public:
		program(string);
		~program();
		string filename;
		int comparisonFlag;
		void compile();
		void execute();
		void print();
};
#endif
