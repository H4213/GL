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

void Programme::executer(map<string,double> &mapV)
{
	if(!partieDeclarative->estVide())
	{
		partieDeclarative->executer(mapV);
	}
	if(!partieInstructive->estVide())
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

