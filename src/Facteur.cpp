#include "Facteur.h"

Facteur::Facteur():Terme(Identifiants::ID_FACTEUR)
{
	_symbole_string = "Facteur";
	est_vide = true;
}

virtual vector<Id*> getIds()
{
}
