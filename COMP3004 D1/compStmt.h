#ifndef JUMPSTMT_H
#define JUMPSTMT_H
#include <string>
#include "statement.h"

class compstmt : public statement
{
	public:
		compstmt();
		~compstmt();
		void compile(string instr);
		void run();
	private:
};
#endif
