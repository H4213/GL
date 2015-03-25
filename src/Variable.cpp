#include "Variable.h"

Variable::Variable(string n):Facteur(Identifiants::ID_VARIABLE)
{
	nom = n;
	_symbole_string = "Variable "+n;
}


double Variable::eval(map<string,double> &mapV)
{
	double valeur;
	//Verification si la variable est declaree
	if(mapV.find(nom) != mapV.end())
	{
		valeur = mapV[nom];
	}
	else
	{
		// TODO: peut etre avoir un symbole Erreur, creer Erreur.h avec une struct enum + strng (id et description des erreurs)
		// e = Erreur("Variable inexistante");
	}


	//return d;
	return 0;
}

string Variable::getNom()
{
	return nom;
}
