#include "InstructionAffectation.h"
#include "Identifiants.h"

InstructionAffectation::InstructionAffectation(Variable v, Expression e):Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION)
{
	variable = v;
	expression = e;
	_symbole_string = "InstructionAffectation";
}