#include "InstructionEcrire.h"

#include <iostream>

InstructionEcrire::InstructionEcrire( Expression *e):Instruction(Identifiants::ID_INSTRUCTIONECRIRE)
{
	expression = e;
	_symbole_string = "InstructionEcrire";
}

void InstructionEcrire::transformation(vector<pair<Id*,Nombre*> > constantes)
{

	expression=expression->transformation(constantes);
	return;
}

vector<Id*> InstructionEcrire::getIds()
{
	vector<Id*> resultat= expression->getIds();
	return resultat;
}

void InstructionEcrire::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	cout << expression->eval(mapV,mapC) << endl;
}

void InstructionEcrire::print()
{
	cout<<"ecrire ";
	expression->print();
	cout<<" ;"<<endl;
}

