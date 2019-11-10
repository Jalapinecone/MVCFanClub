#ifndef RUNPROGRAM_H
#define RUNPROGRAM_H
#include <string>
#include "functionInterface.h"

class runProgram : public functionInterface
{
	public:
		void execute(program &p);
		runProgram();
};
#endif

                                                                                      
