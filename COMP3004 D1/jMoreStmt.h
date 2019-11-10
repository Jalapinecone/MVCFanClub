#ifndef JMORESTMT_H
#define JMORESTMT_H
#include <string>
#include "statement.h"

class jmorestmt : public statement
{
	public:
		jmorestmt(string);
		~jmorestmt();
		void compile(string instr);
		void run();
	private:
		string instructions;
};
#endif
