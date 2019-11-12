#ifndef ENDSTMT_H
#define ENDSTMT_H
#include <string>
#include <vector>
#include "statement.h"

//endstmt initializer - inherited from statement abstract class
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
