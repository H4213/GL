#include "DeclarationVariable.h"

#include <iostream>
using namespace std;


DeclarationVariable::DeclarationVariable(Variable *v, DeclarationVariable *dV) : Declaration(Identifiants::ID_DECLARATIONVARIABLE)
{
	variable = v;
	declarationAutreVariable = dV;
	_symbole_string = "Declaration de la variable " + variable->getNom();
	
}

void DeclarationVariable::executer(map<string,double> &mapV)
{
	if (!declarationAutreVariable->estVide())
	{
		declarationAutreVariable->executer(mapV);		
	}
	mapV[variable->getNom()]; 	
}

void DeclarationVariable::print()
{
	cout << _symbole_string << endl;
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