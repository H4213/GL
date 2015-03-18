#include "PartieDeclarative.h"

#include <string>

PartieDeclarative::PartieDeclarative(Declaration d, PartieDeclarative* partieD) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	_symbole_string = "PartieDeclarative";

	sousPartieDeclarative = partieD;	
}