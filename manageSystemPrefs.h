#ifndef MANAGESYSTEMPREFS_H
#define MANAGESYSTEMPREFS_H
#include <string>
#include "functionInterface.h"

//Not a required implementation for D1
class manageSystemPrefs : public functionInterface
{
	public:
		void execute();
		manageSystemPrefs();
};
#endif
