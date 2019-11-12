#ifndef SCAPESMAIN_H
#define SCAPESMAIN_H
#include "functionInterface.h"
#include <vector>


//functionInterface initializer
class SCAPESmain
{
	public:
		void setFunctionInterface(functionInterface*);
		void execute(program &p);
		functionInterface* _funInt;

};
#endif
