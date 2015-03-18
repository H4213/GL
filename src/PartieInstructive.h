#if !defined ( PARTIEINSTRUCTIVE_H )
#define PARTIEINSTRUCTIVE_H
#include "Symbole.h"
#include "Instruction.h"
#include "Identifiants.h"

class PartieInstructive : public Symbole {

public:
	PartieInstructive(Instruction i, PartieInstructive* partieI); //Voir de passer vector<Instruction> et faire constructeur recurssif...
	PartieInstructive():Symbole(Identifiants::ID_PARTIEINSTRUCTIVE){}
	virtual ~PartieInstructive(){}

private:
	Instruction instruction;
	PartieInstructive* sousPartieInstructive;

};


#endif 