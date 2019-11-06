#ifndef SCAPESMAIN_H
#define SCAPESMAIN_H
#include "functionInterface.h"

class SCAPESmain
{
	public:
		void setFunctionInterface(functionInterface*);
		void execute();
		functionInterface* _funInt;		

};
#endif
