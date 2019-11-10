#ifndef CREATEPROGRAM_H
#define CREATEPROGRAM_H
#include <string>
#include "functionInterface.h"
#include "program.h"

class createProgram : public functionInterface
{
	public:
		void execute(program &p);
		createProgram();
};
#endif
