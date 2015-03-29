#include "Id.h"

#include <string>
using namespace std;


Id::Id(string nom):Facteur(Identifiants::ID_ID)
{
	_symbole_string = nom;
}

vector<Id*> Id::getIds()
{
	vector<Id*> result;
	result.push_back(this);
	return result;
}

string Id::getNom() const
{
	return _symbole_string;
}

bool Id::operator==(const Id& b)
{
    if (_symbole_string==b.getNom())
	{
        return true;
	}
    else
	{
        return false;
	}
}

double Id::eval(map<string,double> &mapV , map<string,double> &mapC)
{
	double valeur = 0;
	string nom_var = getNom();
	if (estVariable(nom_var, mapV))
	{
		valeur = mapV[nom_var];
	}
	else if(estConstante(nom_var, mapC))
	{
		valeur = mapC[nom_var];
	}
	else
	{
		//ERREUR
	}
	return valeur;
}
