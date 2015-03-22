#if !defined ( INSTRUCTIONAFFECTATION_H )
#define INSTRUCTIONAFFECTATION_H
#include "Instruction.h"
#include "Expression.h"
#include "Variable.h"

class InstructionAffectation : public Instruction {

public:
	InstructionAffectation(Variable *v, Expression *e);
	InstructionAffectation():Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION){}
	virtual ~InstructionAffectation(){}
	
	virtual void executer(map<string,double> &mapV){}

private:
	Variable *variable;
	Expression *expression;

};


#endif 