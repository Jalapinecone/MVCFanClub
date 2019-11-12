#ifndef CREATEPROGRAM_H
#define CREATEPROGRAM_H
#include <string>
#include "functionInterface.h"
#include "program.h"

//Create program initializer - inherits from program and functionInterface class
class createProgram : public functionInterface
{
	public:
		void execute(program &p);
		createProgram();
		~createProgram();
};
#endif
