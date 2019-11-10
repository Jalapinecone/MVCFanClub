#ifndef JUMPSTMT_H
#define JUMPSTMT_H
#include <string>
#include "statement.h"

class jumpstmt : public statement
{
	public:
		jumpstmt(string);
		~jumpstmt();
		void compile(string instr);
		void run();
	private:
		string instructions;
};
#endif
