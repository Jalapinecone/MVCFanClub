#ifndef JMORESTMT_H
#define JMORESTMT_H
#include <string>
#include "statement.h"

class jmorestmt : public statement
{
	public:
		jmorestmt();
		~jmorestmt();
		void compile(string instr);
		void run();
	private:
};
#endif
