#ifndef JUMPSTATEMENT_H
#define JUMPSTATEMENT_H
#include <string>
#include <vector>
#include "statement.h"

//jumpstmt initializer - inherited from statement abstract class
class jumpstatement : public statement
{
	public:
		jumpstatement(string);
		~jumpstatement();
		void compile(string instr);
		void run();
	private:
		string instructions;
}; 
#endif
