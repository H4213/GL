#include "Programme.h"
#include "Identifiants.h"

Programme::Programme(PartieDeclarative partieD, PartieInstructive partieI) : Symbole(Identifiants::ID_PROGRAMME)
{
	PartieDeclarative = partieD;
	PartieInstructive = partieI;
	_symbole_string = "Programme";
}