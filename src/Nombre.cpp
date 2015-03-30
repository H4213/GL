#include "Nombre.h"
#include <stdlib.h>
#include <iostream>


Nombre::Nombre(string v):Facteur(Identifiants::ID_NOMBRE)
{
	valeur = atof(v.c_str());
	_symbole_string = v;
}
Expression* Nombre::transformation(map<string,double> constantes)
{
	return this;
}
double Nombre::eval(map<string,double> &mapV)
{
	return valeur;
}

double Nombre::getValeur()
{
	return valeur;
}
vector<Id*> Nombre::getIds()
{
	vector<Id*> result;
	return result;
}

string Nombre::getStrValeur()
{
	return _symbole_string;
}
