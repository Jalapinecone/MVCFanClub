#ifndef ENDSTMT_H
#define ENDSTMT_H
#include <string>
#include <vector>
#include "statement.h"

class endstmt : public statement
{
	public:
		endstmt(string);
		~endstmt();
		void compile(string instr);
		void run();
		vector<char*> split(string);
	private:
		string instructions;
		vector<operand*> operands;
};
#endif
