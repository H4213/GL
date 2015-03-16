#include "PartieInstructive.h"
#include "Identifiants.h"

PartieInstructive::PartieInstructive(Intruction i, PartieInstructive partieI) : Symbole(Identifiants::ID_PARTIEINSTRUCTIVE)
{
	instruction = i;	
	_symbole_string = "PartieInstructive";
	
	sousPartieInstructive = partieI;
}