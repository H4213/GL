#include "InstructionEcrire.h"

InstructionEcrire::InstructionEcrire( Expression e):Instruction(Identifiants::ID_INSTRUCTIONECRIRE)
{
	expression = e;	
	_symbole_string = "InstructionEcrire";
	//TODO
}