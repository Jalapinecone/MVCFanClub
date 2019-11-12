#ifndef JMORESTMT_H
#define JMORESTMT_H
#include <string>
#include <vector>
#include "statement.h"

//jmorestmt initializer - inherited from statement abstract class
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
