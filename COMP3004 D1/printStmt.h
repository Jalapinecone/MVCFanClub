#ifndef PRINTSTMT_H
#define PRINTSTMT_H
#include <string>
#include <vector>
#include "statement.h"

class printstmt : public statement
{
	public:
		printstmt(string);
		~printstmt();
		void compile(string instr);
		void run();
		vector<char*> split(string);	
	private:
		string instructions;
		vector<operand*> operands;
};
#endif
