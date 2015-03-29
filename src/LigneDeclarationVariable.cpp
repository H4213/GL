#include "LigneDeclarationVariable.h"
#include <iostream>
#include <climits>

LigneDeclarationVariable::LigneDeclarationVariable(Id* idO, DeclarationVariable* dv)
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

vector<Id*> LigneDeclarationVariable::getVariables()
{
	vector<Id*> result;
	result.push_back(id);
	if(declarationVariable->estVide()==false)
	{
		vector<Id*> autresVariables = declarationVariable->getVariables();
		result.insert(result.end(),autresVariables.begin(), autresVariables.end());
	}

	return result;
}

vector<Id*> LigneDeclarationVariable::getConstantes()
{
	vector<Id*> result;
	return result;
}

void LigneDeclarationVariable::executer(map<string,double> &mapV , map<string,double> &mapC)
{
    if(declarationVariable->estVide()==false)
	{
		declarationVariable->executer(mapV , mapC);
	}
    mapV[id->getNom()]= INT_MAX;
}
