#include "InstructionLire.h"

#include <iostream>

InstructionLire::InstructionLire(Id *idO):Instruction(Identifiants::ID_INSTRUCTIONLIRE)
{
	id = idO;
	_symbole_string = "InstructionLire";
}
Instruction* InstructionLire::transformation(vector<pair<Id*,Nombre*> > constantes){
	Instruction* i;
	return i;
}

vector<Id*> InstructionLire::getIds()
{
		cout<<"ici"<<endl;

	vector<Id*> result;
	result.push_back(id);
	return result;

}
void InstructionLire::executer(map<string,double> &mapV)
{
	double valeur;
	if(not(cin >> valeur))
	{
		cout<< "error!!!"<<endl;
		//Erreur
	}
	else
	{
		string nom_var = id->getNom();
		if (mapV.find(nom_var) != mapV.end())
		{
			mapV[nom_var] = valeur;
		}
		else
		{
			cout<< "error!!!"<<endl;
			//Erreur
		}
	}
}
