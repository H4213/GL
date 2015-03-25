#include "InstructionLire.h"

#include <iostream>

InstructionLire::InstructionLire(Variable *v):Instruction(Identifiants::ID_INSTRUCTIONLIRE)
{
	variable = v;	
	_symbole_string = "InstructionEcrire";
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
		string nom_var = variable->getNom();
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

