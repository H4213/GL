#include "DeclarationConstante.h"

#include <iostream>

DeclarationConstante::DeclarationConstante(Constante *c, DeclarationConstante *dC) : Declaration(Identifiants::ID_DECLARATIONCONSTANTE)
{
	constante = c;
	declarationAutreConstante = dC;
	_symbole_string = "Declaration de la constante " + constante->getNom();
}

void DeclarationConstante::executer(map<string,double> &mapV)
{
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->executer(mapV);
	}
	mapV[constante->getNom()] = constante->getValeur();
}

void DeclarationConstante::print()
{
	cout << _symbole_string << endl;
	if(!declarationAutreConstante->estVide())
	{
		declarationAutreConstante->print();
	}
}

