#if !defined ( INSTRUCTIONLIRE_H )
#define INSTRUCTIONLIRE_H
#include "Instruction.h"
#include "Variable.h"


class InstructionLire : public Instruction {

public:
	InstructionLire();
	virtual ~InstructionLire(){}

private:
	Variable variable;

};


#endif 