#if !defined ( INSTRUCTIONAFFECTATION_H )
#define INSTRUCTIONAFFECTATION_H
#include "Instruction.h"
#include "Expression.h"
#include "Variable.h"

class InstructionAffectation : public Instruction {

public:
	InstructionAffectation(Variable *v, Expression *e);
	InstructionAffectation():Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION){est_vide = true;}
	virtual ~InstructionAffectation(){}
	
	Variable* getVariable(){return variable;}
	Expression* getExpression(){return expression;}
	virtual void executer(map<string,double> &mapV);

private:
	Variable *variable;
	Expression *expression;

};


#endif 