#ifndef JUMPSTMT_H
#define JUMPSTMT_H
#include <string>
#include <vector>
#include "statement.h"

class compstmt : public statement
{
	public:
		compstmt(string);
		~compstmt();
		void compile(string instr);
		void run();
		vector <char *> split(string);
	private:
		// vector<operand*> operands;	
		string instructions;
};
#endif
