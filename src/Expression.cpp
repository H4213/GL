#include "Expression.h"
#include <iostream>

Expression::Expression():Symbole(Identifiants::ID_EXPRESSION)
{
	_symbole_string = "Expression";
	est_vide = true;
}


Expression* Expression::transformation(map<string,double> constantes)
{
}


