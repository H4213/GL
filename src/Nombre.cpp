#include "Nombre.h"

Nombre::Nombre(double v):Expression(Identifiants::ID_NOMBRE)
{
	valeur = v;
	_symbole_string = "Nombre";
}

double Nombre::eval(map<string,double> &mapV)
{
	return valeur;
}

double Nombre::getValeur()
{
	return valeur;
}