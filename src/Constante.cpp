#include "Constante.h"

#include <string>

Constante::Constante(string n, double v):Expression(Identifiants::ID_CONSTANTE)
{
	nom = n;
	valeur = v;
	_symbole_string = "Constante ";
}

void Constante::executer(map<string,double> &mapV)
{
	
}

string Constante::getNom()
{
	return nom;
}

double Constante::getValeur()
{
	return valeur;
}