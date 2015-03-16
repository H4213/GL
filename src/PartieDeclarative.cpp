#include "PartieDeclarative.h"
#include "Identifiants.h"

#include <string>

PartieDeclarative::PartieDeclarative(Declaration d, PartieDeclarative partD) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	_symbole_string = "PartieDeclarative";

	sousPartieDeclarative= partieD;	
}