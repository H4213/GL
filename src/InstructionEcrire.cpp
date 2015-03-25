#include "InstructionEcrire.h"

#include <iostream>

InstructionEcrire::InstructionEcrire( Expression *e):Instruction(Identifiants::ID_INSTRUCTIONECRIRE)
{
	expression = e;	
	_symbole_string = "InstructionEcrire";
}

void InstructionEcrire::executer(map<string,double> &mapV)
{
	cout << expression->eval(mapV) << endl;
}
