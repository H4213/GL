#include "InstructionEcrire.h"

#include <iostream>

InstructionEcrire::InstructionEcrire( Expression *e):Instruction(Identifiants::ID_INSTRUCTIONECRIRE)
{
	expression = e;	
	_symbole_string = "InstructionEcrire";
}
Instruction* Instruction::transformation(vector<pair<Id*,Nombre*> > constantes)
{
	
}

vector<Id*> InstructionEcrire::getIds()
{
		cout<<"lol"<<endl;

	vector<Id*> resultat= expression->getIds();
	return resultat;
}
void InstructionEcrire::executer(map<string,double> &mapV)
{
	cout << expression->eval(mapV) << endl;
}
