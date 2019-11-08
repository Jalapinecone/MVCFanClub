#ifndef READSTMT_H
#define READSTMT_H
#include <string>
#include "statement.h"

class readstmt : public statement
{
	public:
		readstmt();
		~readstmt();
		void compile(string instr);
		void run();
	private:
};
#endif
