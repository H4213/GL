#include "Programme.h"
#include <iostream>

Programme::Programme(PartieDeclarative *partieD, PartieInstructive *partieI) : Symbole(Identifiants::ID_PROGRAMME)
{
	partieDeclarative = partieD;
	partieInstructive = partieI;
	_symbole_string = "Programme";
}

Programme::~Programme()
{
	partieDeclarative->~PartieDeclarative();
	partieInstructive->~PartieInstructive();
	delete partieDeclarative;
	delete partieInstructive;
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


	if (partieDeclarative->estVide()==false)
	{


    result= partieDeclarative->getVariables();

	}


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
	//cout << "\n------ Impression du programme -------\n" << endl;
	if(!partieDeclarative->estVide())
	{
		partieDeclarative->print();
	}
	if(!partieInstructive->estVide())
	{
		partieInstructive->print();
	}
	//cout << "\n------- Fin du programme -------" << endl;
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


