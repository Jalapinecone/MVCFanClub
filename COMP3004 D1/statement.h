#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include "operand.h"

class statement
{
        public:
                statement();
                ~statement();
		void compile(string instr);
		void run();
        private:
};
#endif

