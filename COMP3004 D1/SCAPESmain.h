#ifndef SCAPESMAIN_H
#define SCAPESMAIN_H
#include "functionInterface.h"
#include <vector>

class SCAPESmain
{
	public:
		void setFunctionInterface(functionInterface*);
		void execute(vector<string> &v);
		functionInterface* _funInt;

};
#endif
