#include "LigneDeclarationVariable.h"

LigneDeclarationVariable::LigneDeclarationVariable(Id* idO, DeclarationVariable* dv)
: Declaration(Identifiants::ID_LIGNEDECLARATIONVARIABLE)
{
	id = idO;
	declarationVariable = dv;
}
vector<Id*> LigneDeclarationVariable::getVariables()
{
	vector<Id*> autresVariables = declarationVariable->getVariables();
	vector<Id*> result;
	result.push_back(id);
	result.insert(result.end(),autresVariables.begin(), autresVariables.end());
	return result;
}
vector<Id*> LigneDeclarationVariable::getConstantes	()
{
	vector<Id*> result;
	return result;
}
LigneDeclarationVariable::~LigneDeclarationVariable()
{
	delete id;
	delete declarationVariable;
}
