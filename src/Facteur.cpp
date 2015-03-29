#include "Facteur.h"
#include <iostream>

Facteur::Facteur():Terme(Identifiants::ID_FACTEUR)
{
	_symbole_string = "Facteur";
	est_vide = true;
}


vector<Id*> Facteur::getIds()
{
	cout<<"Facteur"<<endl;
}
