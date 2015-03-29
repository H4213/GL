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

void InstructionAffectation::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	string nom_var = id->getNom();
	double valeur = expression->eval(mapV,mapC);
	
	if (estVariable(nom_var, mapV) && !estConstante(nom_var, mapC))
	{
		mapV[nom_var] = valeur;
	}
	else
	{
		cout<<"tentative d'affecter a une constante"<<endl;
	}
}

void InstructionAffectation::print()
{
	id->print();
	cout<<" := ";
	expression->print();
	cout<<" ;"<<endl;
}