#if !defined ( PARTIEINSTRUCTIVE_H )
#define PARTIEINSTRUCTIVE_H
#include "Symbole.h"
#include "Instruction.h"


class PartieInstructive : public Symbole {

public:
	PartieInstructive(Instruction i, PartieInstructive partieI); //Voir de passer vector<Instruction> et faire constructeur recurssif...
	virtual ~PartieInstructive(){}

private:
	Instruction instruction;
	PartieInstructive sousPartieInstructive;

};


#endif 