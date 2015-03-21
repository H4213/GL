#include "InstructionLire.h"

InstructionLire::InstructionLire(Variable *v):Instruction(Identifiants::ID_INSTRUCTIONLIRE)
{
	variable = v;	
	_symbole_string = "InstructionEcrire";
	//TODO
}