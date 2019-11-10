#ifndef OPERAND_H
#define OPERAND_H
#include <string>
#include "identifier.h"
class operand
{
	public:
		operand();
		operand(string);
		~operand();
	private:
		string eachOperand;
};
#endif
