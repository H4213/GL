#if !defined ( PARTIEINSTRUCTIVE_H )
#define PARTIEINSTRUCTIVE_H
#include "Symbole.h"
#include "Instruction.h"


class PartieInstructive : public Symbole {

public:
	PartieInstructive();
	virtual ~PartieInstructive(){}

private:
	Instruction instruction;
	PartieInstructive sousPartieInstructive;

};


#endif 