#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include "operand.h"

class statement
{
        public:
                statement();
                ~statement();
		virtual void compile(string instr) = 0;
		virtual void run() = 0;
        private:
};
#endif

