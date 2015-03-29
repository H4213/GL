#include "Terme.h"
#include <iostream>

Terme::Terme():Expression(Identifiants::ID_TERME)
{
	_symbole_string = "Terme";
	est_vide = true;
}

vector<Id*> Terme::getIds()
{
	cout<<"terme"<<endl;
}


