#include "Programme.h"
#include "Identifiants.h"

Programme::Programme(PartieDeclarative partieD, PartieInstructive partieI) : Symbole(Identifiants::ID_PROGRAMME)
{
	partieDeclarative = partieD;
	partieInstructive = partieI;
	_symbole_string = "Programme";
}

vector<Variable> Programme::getVariables() {

    return partieDeclarative.getVariables();
}
