#if !defined ( INSTRUCTIONECRIRE_H )
#define INSTRUCTIONECRIRE_H
#include "Instruction.h"
#include "Expression.h"


class InstructionEcrire : public Instruction {

public:
	InstructionEcrire(Expression *e);
	InstructionEcrire():Instruction(Identifiants::ID_INSTRUCTIONECRIRE){est_vide = true;}
	virtual ~InstructionEcrire(){}
	
	Expression* getExpression(){return expression;}
	virtual void executer(map<string,double> &mapV);

private:
	Expression *expression;

};


#endif 
