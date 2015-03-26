#include "Nombre.h"
#include <stdlib.h>



Nombre::Nombre(string v):Facteur(Identifiants::ID_NOMBRE)
{
	valeur = atof(v.c_str());
	_symbole_string = v;
}

double Nombre::eval(map<string,double> &mapV)
{
	return valeur;
}

double Nombre::getValeur()
{
	return valeur;
}

