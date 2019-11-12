#ifndef PRINTSTMT_H
#define PRINTSTMT_H
#include <string>
#include <vector>
#include "statement.h"

//printstmt initializer - inherited from statement abstract class
class printstmt : public statement
{
	public:
		printstmt(string);
		~printstmt();
		void compile(string instr);
		void run();
	private:
		string instructions;
};
#endif
