#include "InstructionLire.h"

#include <iostream>

InstructionLire::InstructionLire(Id *idO):Instruction(Identifiants::ID_INSTRUCTIONLIRE)
{
	id = idO;
	_symbole_string = "InstructionLire";
}

void InstructionLire::transformation(vector<pair<Id*,Nombre*> > constantes){
	return;
}

vector<Id*> InstructionLire::getIds()
{
	vector<Id*> result;
	result.push_back(id);
	return result;

}

void InstructionLire::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	double valeur;
	string nom_var = id->getNom();

	cout<<"Introduire la valeur pour la variable "<<nom_var<<" : ";

	if(not(cin >> valeur))
	{
		cerr<< "ERREUR: Ce n'est pas un chifre"<<endl;
		//Erreur
	}
	else
	{
		if (estVariable(nom_var, mapV) && !estConstante(nom_var, mapC))
		{
			mapV[nom_var] = valeur;
		}
		else
		{
			cerr<< "ERREUR: Variable non declarée"<<endl;
			//Erreur
		}
	}
}

void InstructionLire::print()
{
	cout<<"lire ";
	id->print();
	cout<<";"<<endl;
}
