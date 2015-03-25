#include "DeclarationConstante.h"

#include <iostream>

DeclarationConstante::DeclarationConstante(Id *idO,  Nombre *n, DeclarationConstante *dC) : Declaration(Identifiants::ID_DECLARATIONCONSTANTE)
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
	//mapV[constante->getNom()] = constante->getValeur();
}

void DeclarationConstante::print()
{
	cout << _symbole_string << endl;
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->print();
	}
}

