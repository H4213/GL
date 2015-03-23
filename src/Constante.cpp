#include "Constante.h"
#include "Nombre.h"

Constante::Constante(string n, double v):Expression(Identifiants::ID_CONSTANTE)
{
	nom = n;
	valeur = v;
	_symbole_string = "Constante ";
}

double Constante::eval(map<string,double> &mapV)
{
	//TODO: Peut etre, plutot chercher dans la map la valeur de la constante?
	return valeur;
}

string Constante::getNom()
{
	return nom;
}

double Constante::getValeur()
{
	return valeur;
}