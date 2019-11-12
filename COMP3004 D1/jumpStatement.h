#ifndef JUMPSTATEMENT_H
#define JUMPSTATEMENT_H
#include <string>
#include <vector>
#include "statement.h"

class jumpstatement : public statement
{
	public:
		jumpstatement(string);
		~jumpstatement();
		void compile(string instr);
		void run();
		vector <char *> split(string);
	private:
		string instructions;
		// vector<operand*> operands;
}; 
#endif
