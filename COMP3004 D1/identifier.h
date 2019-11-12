#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <string>
using namespace std;

//Identifier class initialization
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
