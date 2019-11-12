#ifndef LABEL_H
#define LABEL_H
#include <string>
#include "identifier.h"

//Inherits from the identifier class
//Label initializer class
class label : public identifier
{
	public:
		label();
		label(string n);
		~label();
	private:

};
#endif
