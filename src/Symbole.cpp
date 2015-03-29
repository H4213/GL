#include "Symbole.h"
#include "Identifiants.h"
#include <string>
#include <iostream>

using namespace std;

Symbole::Symbole()
{
	_ident = Identifiants::ID_SYMBOLE;
	_symbole_string = "Symbole";
	est_vide = true;
}

void Symbole::print(){
	cout << _symbole_string << " | ";
}

bool Symbole::estConstante(string nom, map<string,double> &mapC)
{
	if (mapV.find(nom) == mapC.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Symbole::estVariable(string nom, map<string,double> &mapV)
{
	if (mapV.find(nom) == mapV.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}