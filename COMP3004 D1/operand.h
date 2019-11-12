#ifndef OPERAND_H
#define OPERAND_H
#include <string>
#include "identifier.h"

//operand initializer
class operand
{
	public:
		operand();
		operand(string);
		~operand();
		string getName();
		string eachOperand;
	private:
};
#endif
