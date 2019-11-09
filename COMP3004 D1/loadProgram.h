#ifndef LOADPROGRAM_H
#define LOADPROGRAM_H
#include <string>
#include <vector>
#include "functionInterface.h"

class loadProgram : public functionInterface
{
	public:
		void execute(vector<string> &v);
		loadProgram();
	private:
		string fileName;
		string text;
		int counter = 0;
};
#endif

                                                                                      
