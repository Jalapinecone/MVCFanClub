#ifndef SAVEPROGRAM_H
#define SAVEPROGRAM_H
#include <string>
#include <vector>
#include "functionInterface.h"

//loadProgram initializer - inherits from functionInterface class
class saveProgram : public functionInterface
{
	public:
		void execute(program &p);
	private:

};
#endif
