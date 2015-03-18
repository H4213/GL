#if !defined ( INSTRUCTIONAFFECTATION_H )
#define INSTRUCTIONAFFECTATION_H
#include "Instruction.h"
#include "Expression.h"
#include "Variable.h"
#include "Identifiants.h"

class InstructionAffectation : public Instruction {

public:
	InstructionAffectation(Variable v, Expression e);
	InstructionAffectation():Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION){}
	virtual ~InstructionAffectation(){}

private:
	Variable variable;
	Expression expression;

};


#endif 