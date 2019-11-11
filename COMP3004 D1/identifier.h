#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <string>
class identifier
{
	public:
		identifier();
		identifier(string n);
		~identifier();
		string getName();
	protected:
		string name;
};
#endif
