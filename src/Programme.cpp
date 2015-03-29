#include "Programme.h"
#include <iostream>

Programme::Programme(PartieDeclarative *partieD, PartieInstructive *partieI) : Symbole(Identifiants::ID_PROGRAMME)
{
	partieDeclarative = partieD;
	partieInstructive = partieI;
	_symbole_string = "Programme";
}

vector<Instruction*> Programme::getInstructions()
{
	return partieInstructive->getInstructions();
}

vector<Id*> Programme::getVariables() {
    return partieDeclarative->getVariables();
}

vector<Id*> Programme::getConstantes()
{
    return partieDeclarative->getConstantes();
}

void Programme::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	if(!partieDeclarative->estVide())
	{
		partieDeclarative->executer(map_variables , mapC);
	}

	if(!partieInstructive->estVide())
	{
		partieInstructive->executer(mapV , mapC);
	}
}

void Programme::print()
{
	if(!partieDeclarative->estVide())
	{
		partieDeclarative->print();
	}
	if(!partieInstructive->estVide())
	{
		partieInstructive->print();
	}
}

void Programme::afficherVariables()
{
	map<string,double>::iterator it;
	for (it=map_variables.begin(); it!=map_variables.end(); ++it)
	{
		cout << it->first << " => ";
		if(it->second == 0) cout<< "vide"<<endl;
		else
		{
			cout<< it->second <<endl;
		}
	}
}

void Programme::afficherConstantes()
{
	map<string,double>::iterator it;
	for (it=map_constantes.begin(); it!=map_constantes.end(); ++it)
	{
		cout << it->first << " => ";
		if(it->second == 0) cout<< "vide"<<endl;
		else
		{
			cout<< it->second <<endl;
		}
	}
}

