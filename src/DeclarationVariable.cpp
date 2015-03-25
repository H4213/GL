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
	//TODO: à l'initialisation la valeur est igual a 0 et pas a NULL
	// je pense qu'il y a pas de soucis parce que l'analyse statique ne laisserai pas afficher une variable vide...
	if (declarationAutreVariable != NULL)
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

void DeclarationVariable::comptageVariables()
{
	static int cpt = 0;
	cpt++;
	cout << cpt << endl;
	if(!declarationAutreVariable->estVide())
	{
		declarationAutreVariable->comptageVariables();
	}
	
}