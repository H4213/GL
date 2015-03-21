#if !defined ( INSTRUCTIONECRIRE_H )
#define INSTRUCTIONECRIRE_H
#include "Instruction.h"
#include "Expression.h"
#include "Identifiants.h"


class InstructionEcrire : public Instruction {

public:
	InstructionEcrire(Expression *e);
	InstructionEcrire():Instruction(Identifiants::ID_INSTRUCTIONECRIRE){}
	virtual ~InstructionEcrire(){}
	
	virtual void executer();

private:
	Expression *expression;

};


#endif 