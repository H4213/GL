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
	vector<Id*> result;
	result.push_back(id);
	return result;

}

void InstructionLire::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	double valeur;
	string nom_var = id->getNom();
	bool double_ok = false;

	while(!double_ok)
	{
		//cout<<"Introduire la valeur pour la variable "<<nom_var<<" : ";

		if(not(cin >> valeur))
		{
			cin.clear();
      		while (cin.get() != '\n') ;
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
			double_ok = true;
		}
	}


}

void InstructionLire::print()
{
	cout<<"lire ";
	id->print();
	cout<<";"<<endl;
}
