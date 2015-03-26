#include "Instruction.h"

Instruction::Instruction() : Symbole(Identifiants::ID_INSTRUCTION)
{
	_symbole_string = "Instruction";
	est_vide = true;
}

vector<Id*> Instruction::getIds()
{
}
