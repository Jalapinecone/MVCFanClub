#ifndef SAVEPROGRAM_H
#define SAVEPROGRAM_H
#include <string>
#include <vector>
#include "functionInterface.h"

class saveProgram : public functionInterface
{
	public:
		void execute(program &p);
	private:
		string text;

};
#endif
