#include "PartieDeclarative.h"

#include <iostream>

PartieDeclarative::PartieDeclarative(Declaration *d, PartieDeclarative *pD) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	sousPartieDeclarative = pD;
	_symbole_string = "PartieDeclarative";

}


vector<Variable*> PartieDeclarative::getVariables() {

    // Variable de la déclaration
    vector<Variable*> result;
    result.insert(result.end() , declaration->getVariables().begin() , declaration->getVariables().end());

    // Variables de la sous partie declarative
    vector<Variable*> partVariables = sousPartieDeclarative->getVariables();
    result.insert(result.end() , partVariables.begin() , partVariables.end());

    return result;

}
vector<Constante*> PartieDeclarative::getConstantes() {

    // Variable de la déclaration
    vector<Constante*> result;
    result.insert(result.end() , declaration->getConstantes().begin() , declaration->getConstantes().end());

    // Variables de la sous partie declarative
    vector<Constante*> partConstantes= sousPartieDeclarative->getConstantes();
    result.insert(result.end() , partConstantes.begin() , partConstantes.end());

    return result;

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


