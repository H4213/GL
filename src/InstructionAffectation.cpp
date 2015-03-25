#include "InstructionAffectation.h"

InstructionAffectation::InstructionAffectation(Id *idO, Expression *e):Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION)
{
	id = idO;
	expression = e;
	_symbole_string = "InstructionAffectation";
}

void InstructionAffectation::executer(map<string,double> &mapV)
{
	/*string nom_var = variable->getNom();
	double valeur = expression->eval(mapV);
	if (mapV.find(nom_var) != mapV.end())
	{
		mapV[nom_var] = valeur;
	}
	else
	{
		//Erreur
	}*/
}