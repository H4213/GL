#include "Expression.h"
#include "Symbole.h"
#include "Identifiants.h"

Expression::Expression():Symbole(Identifiants::ID_EXPRESSION)
{
	_symbole_string = "Expression";
}

Expression::Expression(int id):Symbole(id)
{
	
}