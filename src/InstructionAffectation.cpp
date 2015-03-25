#include "InstructionAffectation.h"

InstructionAffectation::InstructionAffectation(Variable *v, Expression *e):Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION)
{
	variable = v;
	expression = e;
	_symbole_string = "InstructionAffectation";
}

void InstructionAffectation::executer(map<string,double> &mapV)
{
	string nom_var = variable->getNom();
	double valeur = expression->eval(mapV);
	if (mapV.find(nom_var) != mapV.end())
	{
		mapV[nom_var] = valeur;
	}
	else
	{
		//Erreur
	}
}

