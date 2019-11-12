#ifndef RUNPROGRAM_H
#define RUNPROGRAM_H
#include <string>
#include "functionInterface.h"

//Not a required implementation for D1
class runProgram : public functionInterface
{
	public:
		void execute(program &p);
		runProgram();
};
#endif

                                                                                      
