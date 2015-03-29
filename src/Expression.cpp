#include "Expression.h"
#include <iostream>

Expression::Expression():Symbole(Identifiants::ID_EXPRESSION)
{
	_symbole_string = "Expression";
	est_vide = true;
}
vector<Id*> Expression::getIds()
{

}
Expression* Expression::transformation(vector<pair<Id*,Nombre*> > constantes)
{
}
