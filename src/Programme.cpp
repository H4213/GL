#include "Programme.h"
#include <iostream>

Programme::Programme(PartieDeclarative *partieD, PartieInstructive *partieI) : Symbole(Identifiants::ID_PROGRAMME)
{
	partieDeclarative = partieD;
	partieInstructive = partieI;
	_symbole_string = "Programme";
}

vector<Variable*> Programme::getVariables() {

    return partieDeclarative->getVariables();
}

vector<Constante*> Programme::getConstantes()
{
    return partieDeclarative->getConstantes();
}

void Programme::executer(map<string,double> &mapV)
{
	if(partieDeclarative!=NULL)
	{
		partieDeclarative->executer(mapV);
	}
	if(partieInstructive!=NULL)
	{
		partieInstructive->executer(mapV);
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
