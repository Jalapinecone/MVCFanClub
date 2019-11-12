#ifndef READSTMT_H
#define READSTMT_H
#include <string>
#include <vector>
#include "statement.h"

class readstmt : public statement
{
	public:
		readstmt(string);
		~readstmt();
		void compile(string instr);
		void run();
		vector <char *> split(string);
	private:
		string instructions;
		// vector<operand*> operands;
};
#endif
