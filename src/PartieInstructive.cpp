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
	if (!sousPartieInstructive->estVide())
	{
			vector<Instruction*> autreInstructions = sousPartieInstructive->getInstructions();
			result.insert(result.end(),autreInstructions.begin(),autreInstructions.end());
	}

	result.push_back(instruction);
	return result;
   }

void PartieInstructive::executer(map<string,double> &mapV , map<string,double> &mapC)
{
	if(!sousPartieInstructive->estVide())
	{
		sousPartieInstructive->executer(mapV , mapC);
	}
	instruction->executer(mapV , mapC);
}

void PartieInstructive::print()
{
	if(!sousPartieInstructive->estVide())
	{
		sousPartieInstructive->print();
	}
	instruction->print();
}
