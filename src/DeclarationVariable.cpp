#include "DeclarationVariable.h"
#include "Identifiants.h"

#include <iostream>


DeclarationVariable::DeclarationVariable(string nomVariable, vector<string> autresVariables) : Declaration(Identifiants::ID_DECLARATIONVARIABLE)
{
	_symbole_string = "Declaration de la variable ";
	variable = Variable(nomVariable);

	//construction recurssive, a voir si ça marche
	if(autresVariables.size() > 0)
	{
		// for(int i = 0; i<autresVariables.length ; i++)
		// {
			// string var = autresVariables[i];
			// vector<string> resteDuTableau = resteDuTableau(autresVariables);
			// declarationAutreVariable = DeclarationVariable(var, resteDuTableau);
		// }
	}
	
}

vector<string> DeclarationVariable::resteDuTableau(vector<string> autresVariables)
{
	for(int i=1; i<autresVariables.size(); i++)
	{
		autresVariables[i-1] = autresVariables[i];
	}
	autresVariables.pop_back();
	return autresVariables;
}

void DeclarationVariable::print()
{
	cout << _symbole_string << endl;
	declarationAutreVariable;print();
}