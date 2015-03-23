#include "DeclarationVariable.h"

#include <iostream>
using namespace std;


DeclarationVariable::DeclarationVariable(string nomVariable, vector<string> autresVariables) : Declaration(Identifiants::ID_DECLARATIONVARIABLE)
{
	_symbole_string = "Declaration de la variable " + nomVariable;
	variable = Variable(nomVariable);

	if(autresVariables.size() > 0)
	{
			string var = autresVariables[0];
			resteDuTableau(autresVariables);
			declarationAutreVariable = new DeclarationVariable(var, autresVariables);

			
	} 
	else 
	{
		declarationAutreVariable = NULL;
	}
	
}

void DeclarationVariable::executer(map<string,double> &mapV)
{
	//TODO: à l'initialisation la valeur est igual a 0 et pas a NULL
	// je pense qu'il y a pas de soucis parce que l'analyse statique ne laisserai pas afficher une variable vide...
	mapV[variable.getNom()]; 
	if (declarationAutreVariable != NULL)
	{
		declarationAutreVariable->executer(mapV);		
	}
	
}

void DeclarationVariable::print()
{
	cout << _symbole_string << endl;
	if(declarationAutreVariable != NULL)
	{
		declarationAutreVariable->print();
	}
}

void DeclarationVariable::resteDuTableau(vector<string> &autresVariables)
{
	for(int i=1; i<autresVariables.size(); i++)
	{
		autresVariables[i-1] = autresVariables[i];
	}
	autresVariables.pop_back();
}

void DeclarationVariable::comptageVariables()
{
	static int cpt = 0;
	cpt++;
	cout << cpt << endl;
	if(declarationAutreVariable != NULL)
	{
		declarationAutreVariable->comptageVariables();
	}
	
}