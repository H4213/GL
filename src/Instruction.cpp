#include "Instruction.h"
#include <iostream>
Instruction::Instruction() : Symbole(Identifiants::ID_INSTRUCTION)
{
	_symbole_string = "Instruction";
	est_vide = true;
}
void Instruction::transformation(vector<pair<Id*,Nombre*> > constantes)
{
}

vector<Id*> Instruction::getIds()
{
	cout<<"Instruction"<<endl;
}
