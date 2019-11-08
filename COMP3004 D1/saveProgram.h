#ifndef SAVEPROGRAM_H
#define SAVEPROGRAM_H
#include <string>
#include <vector>
#include "functionInterface.h"

class saveProgram : public functionInterface
{
	public:
		void execute(vector<string> &v);
	private:
		string text;
		string fileName;
		std::vector<string> lines;

};
#endif
