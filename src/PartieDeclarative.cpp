#include "PartieDeclarative.h"

#include <string>
#include <iostream>

PartieDeclarative::PartieDeclarative(Declaration d, vector<Declaration> autresDeclarations) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	_symbole_string = "PartieDeclarative";

	if(autresDeclarations.size() > 0)
	{
		Declaration decla = autresDeclarations[0];
		resteDuTableau(autresDeclarations);
		sousPartieDeclarative = new PartieDeclarative(decla, autresDeclarations);
	} 
	else 
	{
		sousPartieDeclarative = NULL;
	}
}

void PartieDeclarative::resteDuTableau(vector<Declaration> &vectDeclarations)
{
	for(int i=1; i<vectDeclarations.size(); i++)
	{
		vectDeclarations[i-1] = vectDeclarations[i];
	}
	vectDeclarations.pop_back();
}

void PartieDeclarative::print()
{
	cout << _symbole_string << endl;
	if(sousPartieDeclarative != NULL)
	{
		sousPartieDeclarative->print();
	}
}