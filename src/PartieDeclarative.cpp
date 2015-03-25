#include "PartieDeclarative.h"

#include <iostream>

PartieDeclarative::PartieDeclarative(Declaration *d, vector<Declaration*> autresDeclarations) : Symbole(Identifiants::ID_PARTIEDECLARATIVE)
{
	declaration = d;
	_symbole_string = "PartieDeclarative";

<<<<<<< HEAD
	sousPartieDeclarative = partieD;
}

vector<Variable*> PartieDeclarative::getVariables() {

    // Variable de la déclaration
    vector<Variable*> result;
    result.insert(result.end() , declaration.getVariables().begin() , declaration.getVariables().end());

    // Variables de la sous partie declarative
    vector<Variable*> partVariables = sousPartieDeclarative->getVariables();
    result.insert(result.end() , partVariables.begin() , partVariables.end());

    return result;

}
vector<Constante*> PartieDeclarative::getConstantes() {

    // Variable de la déclaration
    vector<Constante*> result;
    result.insert(result.end() , declaration.getConstantes().begin() , declaration.getConstantes().end());

    // Variables de la sous partie declarative
    vector<Constante*> partConstantes= sousPartieDeclarative->getConstantes();
    result.insert(result.end() , partConstantes.begin() , partConstantes.end());

    return result;

}
=======
	if(autresDeclarations.size() > 0)
	{
		Declaration *decla = autresDeclarations[0];
		resteDuTableau(autresDeclarations);
		sousPartieDeclarative = new PartieDeclarative(decla, autresDeclarations);
	} 
	else 
	{
		sousPartieDeclarative = NULL;
	}
}

void PartieDeclarative::executer(map<string,double> &mapV)
{
	declaration->executer(mapV);
	if(sousPartieDeclarative!=NULL)
	{
		sousPartieDeclarative->executer(mapV);
	}
}

void PartieDeclarative::resteDuTableau(vector<Declaration*> &vectDeclarations)
{
	for(int i=1; i<vectDeclarations.size(); i++)
	{
		vectDeclarations[i-1] = vectDeclarations[i];
	}
	vectDeclarations.pop_back();
}

void PartieDeclarative::print()
{
	cout << _symbole_string << endl;
	if(sousPartieDeclarative != NULL)
	{
		sousPartieDeclarative->print();
	}
}
>>>>>>> eba44e39f24c62f3d560db3081ec1095d5871ea5
