#include "Expression.h"
#include <iostream>

Expression::Expression():Symbole(Identifiants::ID_EXPRESSION)
{
	_symbole_string = "Expression";
	est_vide = true;
}
vector<Id*> Expression::getIds()
{
			cout<<"j'arrive ici"<<endl;

}
Expression* Expression::transformation(vector<pair<Id*,Nombre*> > constantes)
{
}
