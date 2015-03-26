#include "PartieInstructive.h"

#include <iostream>

PartieInstructive::PartieInstructive(Instruction *i, PartieInstructive *pI) : Symbole(Identifiants::ID_PARTIEINSTRUCTIVE)
{
	instruction = i;
	sousPartieInstructive = pI;
	_symbole_string = "PartieInstructive";
}

vector<Instruction*> PartieInstructive::getInstructions()
{
	vector<Instruction*> result;
	if (sousPartieInstructive !=NULL)
	{
			vector<Instruction*> autreInstructions = sousPartieInstructive->getInstructions();
			result.insert(result.end(),autreInstructions.begin(),autreInstructions.end());
	}
	result.push_back(instruction);
	return result;
   }

void PartieInstructive::executer(map<string,double> &mapV)
{
	if(!sousPartieInstructive->estVide())
	{
		sousPartieInstructive->executer(mapV);
	}
	instruction->executer(mapV);
}

void PartieInstructive::print()
{
	cout << _symbole_string << endl;
	if(!sousPartieInstructive->estVide())
	{
		sousPartieInstructive->print();
	}
}
