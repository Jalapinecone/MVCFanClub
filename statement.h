#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include "operand.h"
#include "identifier.h"
#include "label.h"


//Statement initializer - abstract class for all user-entered code statements
class statement
{
        public:
                statement();
                ~statement();
		virtual void compile(string instr) = 0;
		virtual void run() = 0;
                vector<operand*> getOperands();
		string getInstruction();
		void setInstruction(string);
		void addOperand(operand*);
		void addLabel(label*);
		vector<label*> getLabels();
		vector <char *> split(string);
        private:
		string instruction;
		vector<operand*> operands;
		vector<label*> labels;
                
};
#endif
