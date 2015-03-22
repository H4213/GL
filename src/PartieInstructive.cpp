#include "PartieInstructive.h"

#include <iostream>

// PartieInstructive::PartieInstructive(Instruction *i, vector<Instruction*> autresInstructions) : Symbole(Identifiants::ID_PARTIEINSTRUCTIVE)
// {
// 	instruction = i;
// 	_symbole_string = "PartieInstructive";

// 	if(autresInstructions.size() > 0)
// 	{
// 		Instruction *ins = autresInstructions[0];
// 		resteDuTableau(autresInstructions);
// 		sousPartieInstructive = new PartieInstructive(ins, autresInstructions);
// 	} 
// 	else 
// 	{
// 		sousPartieInstructive = NULL;
// 	}
// }

void PartieInstructive::executer(map<string,double> &mapV)
{
	cout<< "tchau" << endl;
}

// void PartieInstructive::resteDuTableau(vector<Instruction*> &vectInstructions)
// {
// 	for(int i=1; i<vectInstructions.size(); i++)
// 	{
// 		vectInstructions[i-1] = vectInstructions[i];
// 	}
// 	vectInstructions.pop_back();
// }

// void PartieInstructive::print()
// {
// 	cout << _symbole_string << endl;
// 	if(sousPartieInstructive != NULL)
// 	{
// 		sousPartieInstructive->print();
// 	}
// }