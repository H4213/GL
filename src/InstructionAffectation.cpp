#include "InstructionAffectation.h"
#include <iostream>
#include "Identifiants.h"
#include "Nombre.h"
InstructionAffectation::InstructionAffectation(Id *idO, Expression *e):Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION)
{
	id = idO;
	expression = e;
	_symbole_string = "InstructionAffectation";
}

vector<Id*> InstructionAffectation::getIds()
{
	vector<Id*> result;
	result.push_back(id);
	vector<Id*> temp= expression->getIds();
	if (temp.size()!=0)
	{
        result.insert(result.end(),temp.begin(),temp.end());
	}
	return result;

}

Instruction* InstructionAffectation::transformation(map<string, double> constantes)
{
	Expression * newExpression=expression->transformation(constantes);
	Id * newId=new Id(id->getNom());
	InstructionAffectation* newInstruction=new InstructionAffectation(newId,newExpression);
	return newInstruction;
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
