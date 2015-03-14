#if !defined ( INSTRUCTIONECRIRE_H )
#define INSTRUCTIONECRIRE_H
#include "Instruction.h"
#include "Expression.h"


class InstructionEcrire : public Instruction {

public:
	InstructionEcrire();
	virtual ~InstructionEcrire(){}

private:
	Expression expression;

};


#endif 