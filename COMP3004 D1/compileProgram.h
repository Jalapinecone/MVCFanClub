#ifndef COMPILEPROGRAM_H
#define COMPILEPROGRAM_H
#include <string>
#include "functionInterface.h"

class compileProgram : public functionInterface
{
	public:
		void execute(program &p);
		compileProgram();
};
#endif
