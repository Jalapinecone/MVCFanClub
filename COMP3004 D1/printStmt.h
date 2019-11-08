#ifndef PRINTSTMT_H
#define PRINTSTMT_H
#include <string>
#include "statement.h"

class printstmt : public statement
{
	public:
		printstmt();
		~printstmt();
		void compile(string instr);
		void run();
	private:
};
#endif
