#include "Declaration.h"
// #include "Identifiants.h"

Declaration::Declaration() : Symbole(Identifiants::ID_DECLARATION)
{
	_symbole_string = "Declaration";
	est_vide = true;
}

Declaration::Declaration(int id) : Symbole(id)
{
	
}