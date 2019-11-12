#ifndef JUMPSTMT_H
#define JUMPSTMT_H
#include <string>
#include <vector>
#include "statement.h"

//compstmt initializer - inherited from statement abstract class
class compstmt : public statement
{
	public:
		compstmt(string);
		~compstmt();
		void compile(string instr);
		void run();
	private:
		string instructions;
};
#endif
