#ifndef DECLINTSTMT_H
#define DECLINTSTMT_H
#include <string>
#include "statement.h"

class declintstmt : public statement
{
	public:
		declintstmt();
		~declintstmt();
		void compile(string instr);
		void run();
	private:
};
#endif
