#include "LigneDeclarationVariable.h"
#include <iostream>
#include <climits>
LigneDeclarationVariable::LigneDeclarationVariable(Id* idO, DeclarationVariable* dv)
: Declaration(Identifiants::ID_LIGNEDECLARATIONVARIABLE)
{
	id = idO;
	declarationVariable = dv;
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

<<<<<<< HEAD

vector<pair<Id*,Nombre*> > LigneDeclarationVariable::getConstantesValeurs(){
	vector<pair<Id*,Nombre*> > result;
	return result;
}


=======
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
void LigneDeclarationVariable::executer(map<string,double> &mapV)
{
    if(declarationVariable->estVide()==false)
	{
		declarationVariable->executer(mapV);
	}
    mapV[id->getNom()]= INT_MAX;
}
<<<<<<< HEAD

=======
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
