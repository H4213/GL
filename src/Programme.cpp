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
	vector<Instruction*> result;

		if (partieInstructive->estVide()==false)
		{

		result = partieInstructive->getInstructions();
		}
		return result;
	}

vector<Id*> Programme::getVariables() {
	vector<Id*> result;
			cout<<" Programme1"<<endl;

	if (partieDeclarative->estVide()==false)
	{
		cout<<" ?"<<endl;

    result= partieDeclarative->getVariables();

	}
	for (int i=0; i<result.size();i++)
	{
				cout<<" ?"<<endl;

		cout<<result[i]->getNom()<<endl;
	}
		cout<<" Programme2"<<endl;

	return result;
	
}

vector<Id*> Programme::getConstantes()
{
	vector<Id*> result;
	if (partieDeclarative->estVide()==false)
	{
	
    result = partieDeclarative->getConstantes();

	}
	return  result;
}

void Programme::executer(map<string,double> &mapV)
{
	if(!partieDeclarative->estVide())
	{
		partieDeclarative->executer(mapV);
	}
	afficherVariables();

	if(!partieInstructive->estVide())
	{
		partieInstructive->executer(mapV);
	}
	afficherVariables();
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

map<string, double> Programme::getConstantesValeurs()
	{
		map<string,double> result;
		if (partieDeclarative->estVide()==false)
		{
			result=partieDeclarative->getConstantesValeurs();
		}
		return result;
	}

	

