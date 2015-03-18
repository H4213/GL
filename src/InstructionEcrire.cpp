#include "InstructionEcrire.h"

InstructionEcrire::InstructionEcrire( Expression e):Instruction(Identifiants::ID_INSTRUCTIONECRTIRE)
{
	expression = e;	
	_symbole_string = "InstructionEcrire";
	//TODO
}