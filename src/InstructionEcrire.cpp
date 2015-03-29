#include "InstructionEcrire.h"

#include <iostream>

InstructionEcrire::InstructionEcrire( Expression *e):Instruction(Identifiants::ID_INSTRUCTIONECRIRE)
{
	expression = e;
	_symbole_string = "InstructionEcrire";
}
void InstructionEcrire::transformation(vector<pair<Id*,Nombre*> > constantes)
{
<<<<<<< HEAD
	expression=expression->transformation(constantes);
	return;
}

vector<Id*> InstructionEcrire::getIds()
{
=======
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
	vector<Id*> resultat= expression->getIds();
	return resultat;
}
void InstructionEcrire::executer(map<string,double> &mapV)
{
	cout << expression->eval(mapV) << endl;
}

