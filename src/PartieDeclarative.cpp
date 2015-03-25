#include "PartieDeclarative.h"

#include <iostream>

PartieDeclarative::PartieDeclarative(Declaration *d, PartieDeclarative *pD) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	sousPartieDeclarative = pD;
	_symbole_string = "PartieDeclarative";
}

void PartieDeclarative::executer(map<string,double> &mapV)
{
	if(sousPartieDeclarative!=NULL)
	{
		sousPartieDeclarative->executer(mapV);
	}
	declaration->executer(mapV);
}

void PartieDeclarative::print()
{
	cout << _symbole_string << endl;
	if(sousPartieDeclarative != NULL)
	{
		sousPartieDeclarative->print();
	}
}
