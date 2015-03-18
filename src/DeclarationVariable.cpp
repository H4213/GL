#include "DeclarationVariable.h"

#include <iostream>


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

void DeclarationVariable::resteDuTableau(vector<string> &autresVariables)
{
	for(int i=1; i<autresVariables.size(); i++)
	{
		autresVariables[i-1] = autresVariables[i];
	}
	autresVariables.pop_back();
}

void DeclarationVariable::print()
{
	cout << _symbole_string << endl;
	if(declarationAutreVariable != NULL)
	{
		declarationAutreVariable->print();
	}
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