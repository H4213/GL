#include "PartieInstructive.h"

#include <string>

PartieInstructive::PartieInstructive(Instruction i, PartieInstructive* partieI) : Symbole(Identifiants::ID_PARTIEINSTRUCTIVE)
{
	instruction = i;
	_symbole_string = "PartieInstructive";

	sousPartieInstructive = partieI;	
}