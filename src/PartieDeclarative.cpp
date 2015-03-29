#include "PartieDeclarative.h"

#include <iostream>

PartieDeclarative::PartieDeclarative(Declaration *d, PartieDeclarative *pD) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	sousPartieDeclarative = pD;
	_symbole_string = "PartieDeclarative";

}


vector<Id*> PartieDeclarative::getVariables() {

    vector<Id*> result;
    if (sousPartieDeclarative->estVide()==false)
    {
    // Variables de la sous partie declarative
        vector<Id*> partVariables = sousPartieDeclarative->getVariables();
        result.insert(result.end() , partVariables.begin() , partVariables.end());
	}
	// Variable de la déclaration
	vector<Id*> partVariables2=declaration->getVariables();
    result.insert(result.end() , partVariables2.begin() , partVariables2.end());
    return result;

}

vector<Id*> PartieDeclarative::getConstantes() {
	vector<Id*> result;
	if(sousPartieDeclarative->estVide()==false)
	{
        vector<Id*> partConstantes= sousPartieDeclarative->getConstantes();
        result.insert(result.end() , partConstantes.begin() , partConstantes.end());
	}
    // Variable de la déclaration
        vector<Id*> partConstantes2=declaration->getConstantes();
        result.insert(result.end() , partConstantes2.begin() , partConstantes2.end());

    return result;
}


void PartieDeclarative::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	if(!sousPartieDeclarative->estVide())
	{
		sousPartieDeclarative->executer(mapV , mapC);

	}
	declaration->executer(mapV , mapC);

}

void PartieDeclarative::print()
{
	if(!sousPartieDeclarative->estVide())
	{
		sousPartieDeclarative->print();
	}
	declaration->print();
}

