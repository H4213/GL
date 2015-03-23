#include "Variable.h"

Variable::Variable(string n):Expression(Identifiants::ID_VARIABLE)
{
	nom = n;
	_symbole_string = "Variable "+n;
}

double Variable::eval(map<string,double> &mapV)
{
	double d;
	if(mapV.find(nom) != mapV.end())
	{
		d = mapV[nom];
	}
	else
	{
		// TODO: peut etre avoir un symbole Erreur, creer Erreur.h avec une struct enum + strng (id et description des erreurs)
		// e = Erreur("Variable inexistante");
	}
	
	return d;
}

string Variable::getNom()
{
	return nom;
}
