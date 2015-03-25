#include "Constante.h"
#include "Nombre.h"

Constante::Constante(string n, double v):Expression(Identifiants::ID_CONSTANTE)
{
	nom = n;
	valeur = v;
	_symbole_string = "Constante ";
}

<<<<<<< HEAD
string Constante::getNom()
{
    return nom;
=======
double Constante::eval(map<string,double> &mapV)
{
	//TODO: Peut etre, plutot chercher dans la map la valeur de la constante?
	return valeur;
}

string Constante::getNom()
{
	return nom;
>>>>>>> eba44e39f24c62f3d560db3081ec1095d5871ea5
}

double Constante::getValeur()
{
<<<<<<< HEAD
    return valeur;
}
=======
	return valeur;
}
>>>>>>> eba44e39f24c62f3d560db3081ec1095d5871ea5
