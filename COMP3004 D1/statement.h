#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include "operand.h"
#include "identifier.h"
#include "label.h"

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
        private:
		string instruction;
		vector<operand*> operands;
		vector<label*> labels;
                
};
#endif
