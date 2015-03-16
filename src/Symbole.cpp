#include "Symbole.h"
#include <string>
#include <iostream>

using namespace std;

Symbole::Symbole()
{
	_ident = ID_SYMBOLE;
	_symbole_string = "Symbole";
}

void Symbole::print(){
	cout << _symbole_string << endl;
}

