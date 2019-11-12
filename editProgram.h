#ifndef EDITPROGRAM_H
#define EDITPROGRAM_H
#include <string>
#include "functionInterface.h"

class editProgram : public functionInterface
{
	public:
		void execute(program &p);
		editProgram();
};
#endif
