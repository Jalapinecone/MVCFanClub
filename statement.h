#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include "operand.h"

class statement
{
        public:
                statement();
                ~statement();
		virtual void compile(string instr) = 0;
		virtual void run() = 0;
                vector<operand*> operands;
		string instruction;
                vector<operand*> getOperands();
		string getInstruction();
        private:
                
};
#endif
