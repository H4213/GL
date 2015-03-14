#if !defined ( INSTRUCTIONAFFECTATION_H )
#define INSTRUCTIONAFFECTATION_H
#include "Instruction.h"
#include "Expression.h"
#include "Variable.h"


class InstructionAffectation : public Instruction {

public:
	InstructionAffectation();
	virtual ~InstructionAffectation(){}

private:
	Variable variable;
	Expression expression;

};


#endif 