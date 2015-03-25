#include "PartieInstructive.h"

#include <iostream>

PartieInstructive::PartieInstructive(Instruction *i, PartieInstructive *pI) : Symbole(Identifiants::ID_PARTIEINSTRUCTIVE)
{
	instruction = i;
	sousPartieInstructive = pI;
	_symbole_string = "PartieInstructive";
}

void PartieInstructive::executer(map<string,double> &mapV)
{
	if(sousPartieInstructive != NULL)
	{
		sousPartieInstructive->executer(mapV);
	}
	instruction->executer(mapV);
}

void PartieInstructive::print()
{
	cout << _symbole_string << endl;
	if(sousPartieInstructive != NULL)
	{
		sousPartieInstructive->print();
	}
}