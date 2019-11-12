#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include "operand.h"


//Statement initializer - abstract class for all user-entered code statements
class statement
{
        public:
                statement();
                ~statement();
		virtual void compile(string instr) = 0;
		virtual void run() = 0;
		string instruction;
                vector<operand*> operands;
                vector<operand*> getOperands();
		string getInstruction();
                vector <char *> split(string);
        private:
                
                
};
#endif
