#include "DeclarationConstante.h"

#include <iostream>

DeclarationConstante::DeclarationConstante(string nomConstante, double valeur, vector<string> autresConstantes, vector<double> autresValeurs) : Declaration(Identifiants::ID_DECLARATIONCONSTANTE)
{
	constante = Constante(nomConstante,valeur);
	_symbole_string = "Declaration de la constante " + nomConstante;

	if(autresConstantes.size() > 0)
	{
			string cons = autresConstantes[0];
			double val = autresValeurs[0];
			resteDuTableau(autresConstantes, autresValeurs);
			declarationAutreConstante = new DeclarationConstante(cons, val, autresConstantes, autresValeurs);
	} 
	else 
	{
		declarationAutreConstante = NULL;
	}
}

void DeclarationConstante::executer(map<string,double> &mapV)
{
	mapV[constante.getNom()] = constante.getValeur();
	if(declarationAutreConstante!=NULL)
	{
		declarationAutreConstante->executer(mapV);
	}
}

void DeclarationConstante::print()
{
	cout << _symbole_string << endl;
	if(declarationAutreConstante != NULL)
	{
		declarationAutreConstante->print();
	}
}

void DeclarationConstante::resteDuTableau(vector<string> &tabConstantes, vector<double> &tabValeurs)
{
	for(int i=1; i<tabConstantes.size(); i++)
	{
		tabConstantes[i-1] = tabConstantes[i];
		tabValeurs[i-1] = tabValeurs[i];
	}
	tabConstantes.pop_back();
	tabValeurs.pop_back();
}

