#ifndef DECLINTSTMT_H
#define DECLINTSTMT_H
#include <string>
#include <vector>
#include "statement.h"

class declintstmt : public statement
{
	public:
		declintstmt(string);
		~declintstmt();
		void compile(string);
		void run();
		vector<char*> split(string);
	private:
		string instructions;
		// vector<operand*> operands;
};
#endif
