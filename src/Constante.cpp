#include "Constante.h"

#include <string>

Constante::Constante(string n, double v):Expression(Identifiants::ID_CONSTANTE)
{
	nom = n;
	valeur = v;
	_symbole_string = "Constante ";
}