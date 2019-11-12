#ifndef EDITPROGRAM_H
#define EDITPROGRAM_H
#include <string>
#include "functionInterface.h"


//editProgram not a required implement for D1
class editProgram : public functionInterface
{
	public:
		void execute(program &p);
		editProgram();
};
#endif
