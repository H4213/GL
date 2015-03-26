#include "InstructionLire.h"

#include <iostream>

InstructionLire::InstructionLire(Id *idO):Instruction(Identifiants::ID_INSTRUCTIONLIRE)
{
	id = idO;	
	_symbole_string = "InstructionEcrire";
}
vector<Id*> InstructionLire::getIds()
{
	vector<Id*> result;
	result.push_back(id);
	return result;
	
}
void InstructionLire::executer(map<string,double> &mapV)
{
	/*double valeur;
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
	}*/

}
