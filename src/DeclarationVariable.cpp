#include "DeclarationVariable.h"
#include <climits>
#include <iostream>


DeclarationVariable::DeclarationVariable(Id *idO, DeclarationVariable *dV) : Symbole(Identifiants::ID_DECLARATIONVARIABLE)
{
	id = idO;
	declarationAutreVariable = dV;
	_symbole_string = "Declaration de la variable "+ id->getNom();

}
vector<Id*> DeclarationVariable::getVariables()
{
	vector<Id*> result;
	if (declarationAutreVariable->estVide() == false)
	{
        vector<Id*> autresVariables=declarationAutreVariable->getVariables();
        result.insert(result.end(), autresVariables.begin(), autresVariables.end());
	}
	result.push_back(id);
	return result;
}

void DeclarationVariable::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	if (!declarationAutreVariable->estVide())
	{
		declarationAutreVariable->executer(mapV , mapC);
	}
	mapV[id->getNom()]= INT_MAX;
}

void DeclarationVariable::print()
{	
	cout<<", ";
	id->print();
	if(!declarationAutreVariable->estVide())
	{
		declarationAutreVariable->print();
	}
}

void DeclarationVariable::compterVariables()
{
	static int cpt = 0;
	cpt++;
	cout << cpt << endl;
	if(!declarationAutreVariable->estVide())
	{
		declarationAutreVariable->compterVariables();
	}

}
