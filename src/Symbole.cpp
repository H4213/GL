#include "Symbole.h"
#include "Identifiants.h"
#include <string>
#include <iostream>

using namespace std;

Symbole::Symbole()
{
	_ident = Identifiants::ID_SYMBOLE;
	_symbole_string = "Symbole";
}

void Symbole::print(){
	cout << _symbole_string << endl;
}

