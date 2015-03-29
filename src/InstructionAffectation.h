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
	vector<Id*> getIds();
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();
	
private:
	Id *id;
	Expression *expression;

};


#endif 
