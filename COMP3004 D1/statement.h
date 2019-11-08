#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include "operand.h"

class statement
{
        public:
                statement();
                ~statement();
		virtual void compile(string instr);
		virtual void run();
        private:
};
#endif

