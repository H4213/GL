#include "LigneDeclarationVariable.h"

LigneDeclarationVariable::LigneDeclarationVariable(Id*idO, DeclarationVariable*dv)
: Declaration(Identifiants::ID_LIGNEDECLARATIONVARIABLE)
{
	id = idO;
	declarationVariable = dv;
}

LigneDeclarationVariable::~LigneDeclarationVariable()
{
	delete id;
	delete declarationVariable;
}