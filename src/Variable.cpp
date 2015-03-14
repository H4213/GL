#include "Variable.h"
#include "Identifiants.h"

#include <string>

Variable(string n):Expression()
{
	nom=n;
	_symbole_string = "variable "+n;
}