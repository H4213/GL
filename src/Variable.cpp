#include "Variable.h"

#include <string>

Variable::Variable(string n):Expression(Identifiants::ID_VARIABLE)
{
	nom = n;
	_symbole_string = "Variable "+n;
}

void Variable::executer(map<string,double> &mapV)
{
	
}

string Variable::getNom()
{
	return nom;
}