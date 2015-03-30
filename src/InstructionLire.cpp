#include "InstructionLire.h"

#include <iostream>

InstructionLire::InstructionLire(Id *idO):Instruction(Identifiants::ID_INSTRUCTIONLIRE)
{
	id = idO;
	_symbole_string = "InstructionLire";
}

Instruction * InstructionLire::transformation(map<string,double> constantes){
	Instruction * newInstruction = new InstructionLire(id);
	return newInstruction;
}

vector<Id*> InstructionLire::getIds()
{
		cout<<"ici"<<endl;

	vector<Id*> result;
	result.push_back(id);
	return result;

}

void InstructionLire::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	double valeur;
	if(not(cin >> valeur))
	{
		cout<< "Ce n'est pas un double"<<endl;
		//Erreur
	}
	else
	{
		string nom_var = id->getNom();
		if (estVariable(nom_var, mapV) && !estConstante(nom_var, mapC))
		{
			mapV[nom_var] = valeur;
		}
		else
		{
			cout<< "Variable non declarée"<<endl;
			//Erreur
		}
	}
}

void InstructionLire::print()
{
	cout<<"lire ";
	id->print();
	cout<<" ;"<<endl;
}
