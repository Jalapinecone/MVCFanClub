#ifndef FUNCTIONINTERFACE_H
#define FUNCTIONINTERFACE_H
#include <vector>
#include "program.h"

//functionInterface abstract class initialization
class functionInterface
{
	public:
		virtual void execute(program &p);
		functionInterface();
};
#endif
