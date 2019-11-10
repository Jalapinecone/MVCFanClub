#ifndef ENDSTMT_H
#define ENDSTMT_H
#include <string>
#include "statement.h"

class endstmt : public statement
{
	public:
		endstmt(string);
		~endstmt();
		void compile(string instr);
		void run();
	private:
		string instructions;
};
#endif
