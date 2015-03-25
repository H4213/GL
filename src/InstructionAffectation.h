#if !defined ( INSTRUCTIONAFFECTATION_H )
#define INSTRUCTIONAFFECTATION_H
#include "Instruction.h"
#include "Expression.h"
#include "Id.h"

class InstructionAffectation : public Instruction {

public:
	InstructionAffectation(Id *id, Expression *e);
	InstructionAffectation():Instruction(Identifiants::ID_INSTRUCTIONAFFECTATION){est_vide = true;}
	virtual ~InstructionAffectation(){}
	
	Id* getId(){return id;}
	Expression* getExpression(){return expression;}
	virtual void executer(map<string,double> &mapV);

private:
	Id *id;
	Expression *expression;

};


#endif 