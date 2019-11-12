#ifndef READSTMT_H
#define READSTMT_H
#include <string>
#include <vector>
#include "statement.h"

//readstmt initializer - inherited from statement abstract class
class readstmt : public statement
{
	public:
		readstmt(string);
		~readstmt();
		void compile(string instr);
		void run();
	private:
		string instructions;
};
#endif
