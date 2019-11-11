#ifndef JMORESTMT_H
#define JMORESTMT_H
#include <string>
#include <vector>
#include "statement.h"

class jmorestmt : public statement
{
	public:
		jmorestmt(string);
		~jmorestmt();
		void compile(string instr);
		void run();
		vector<char*> split(string);
	private:
		string instructions;
		// vector<operand*> operands;
};
#endif
