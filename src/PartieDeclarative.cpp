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
        if (partVariables.size()!=0)
        {
        result.insert(result.end() , partVariables.begin() , partVariables.end());

		}

	}
	if (declaration->estVide()==false)
	{

// Variable de la déclaration
	vector<Id*> partVariables2=declaration->getVariables();


     if (partVariables2.size()!=0)
	{


    result.insert(result.end() , partVariables2.begin() , partVariables2.end());
	}
}
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


void PartieDeclarative::executer(map<string,double> &mapV)
{
	if(!sousPartieDeclarative->estVide())
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

vector<pair<Id*,Nombre*> > PartieDeclarative::getConstantesValeurs()
{
	vector<pair<Id*,Nombre*> > result;

	if (sousPartieDeclarative->estVide()==false)
	{
		result = sousPartieDeclarative->getConstantesValeurs();
	}

	if(declaration->estVide()==false)
	{
		vector<pair<Id*,Nombre*> > temp=declaration->getConstantesValeurs();
		if (temp.size()!=0)
		{
		result.insert(result.end(),temp.begin(),temp.end());
		}
	}

	return result;
}


