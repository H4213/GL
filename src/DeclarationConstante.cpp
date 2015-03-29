#include "DeclarationConstante.h"

#include <iostream>

DeclarationConstante::DeclarationConstante(Id *idO,  Nombre *n, DeclarationConstante *dC) : Symbole(Identifiants::ID_DECLARATIONCONSTANTE)
{
	id = idO;
	declarationAutreConstante = dC;
	val = n;
	_symbole_string = "Declaration de la constante " /*+ constante->getNom()*/;
}

void DeclarationConstante::executer(map<string,double> &mapV)
{
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->executer(mapV);
	}
	mapV[id->getNom()] = val->getValeur();
}

void DeclarationConstante::print()
{
	cout << _symbole_string << endl;
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->print();
	}
}

vector<Id*> DeclarationConstante::getConstantes()
{
	vector<Id*> result;
	if (declarationAutreConstante->estVide()==false)
	{
		vector<Id*> autresConstantes = declarationAutreConstante->getConstantes();
		result.insert(result.end(),autresConstantes.begin(), autresConstantes.end());
	}
	result.push_back(id);

<<<<<<< HEAD
	return result;
}

vector<pair<Id*,Nombre*> > DeclarationConstante::getConstantesValeurs()
{
	vector<pair<Id*,Nombre*> > result;
	if (declarationAutreConstante->estVide()==false)
	{
		vector<pair<Id*,Nombre*> > vecTemp = declarationAutreConstante->getConstantesValeurs();
		result.insert(result.end(),vecTemp.begin(),vecTemp.end());
	}
	pair<Id*, Nombre*> temp(id,val);
	result.push_back(temp);
=======
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
	return result;
}



