#include "DeclarationConstante.h"

#include <iostream>

DeclarationConstante::DeclarationConstante(Id *idO,  Nombre *n, DeclarationConstante *dC) : Symbole(Identifiants::ID_DECLARATIONCONSTANTE)
{
	id = idO;
	declarationAutreConstante = dC;
	val = n;
	_symbole_string = "Declaration de la constante " + id->getNom();
}

void DeclarationConstante::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->executer(mapV , mapC);
	}
	mapC[id->getNom()] = val->getValeur();
}

void DeclarationConstante::print()
{
	cout<<", ";
	id->print();
	cout<<"=";
	val->print();
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->print();
	}
}

vector<Id*> DeclarationConstante::getConstantes()
{
	vector<Id*> result;
	if (!declarationAutreConstante->estVide())
	{
		vector<Id*> autresConstantes = declarationAutreConstante->getConstantes();
		result.insert(result.end(),autresConstantes.begin(), autresConstantes.end());
	}
	result.push_back(id);

	return result;
}


