#include "Instruction.h"
#include <iostream>

Instruction::Instruction() : Symbole(Identifiants::ID_INSTRUCTION)
{
	_symbole_string = "Instruction";
	est_vide = true;
}

Instruction* Instruction::transformation(map<string,double>  constantes)
{
	
}

vector<Id*> Instruction::getIds()
{
	cout<<"Instruction"<<endl;
}
