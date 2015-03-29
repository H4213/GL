#include "DeclarationVariable.h"
#include <climits>
#include <iostream>
using namespace std;


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
void DeclarationVariable::executer(map<string,double> &mapV)
{
    cout << "here" << endl;
	if (!declarationAutreVariable->estVide())
	{
		declarationAutreVariable->executer(mapV);
	}
	mapV[id->getNom()]= INT_MAX;
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
