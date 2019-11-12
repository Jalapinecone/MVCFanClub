#ifndef LOADPROGRAM_H
#define LOADPROGRAM_H
#include <string>
#include <vector>
#include "functionInterface.h"

//loadProgram initializer - inherits from functionInterface class
class loadProgram : public functionInterface
{
	public:
		void execute(program &p);
		loadProgram();
	private:
		string text;
		int counter = 0;
};
#endif

                                                                                      
