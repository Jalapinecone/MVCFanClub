#ifndef DECLINTSTMT_H
#define DECLINTSTMT_H
#include <string>
#include <vector>
#include "statement.h"

//declintstmt initializer - inherited from statement abstract class
class declintstmt : public statement
{
	public:
		declintstmt(string);
		~declintstmt();
		void compile(string);
		void run();
	private:
		string instructions;
};
#endif
