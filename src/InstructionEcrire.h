#if !defined ( INSTRUCTIONECRIRE_H )
#define INSTRUCTIONECRIRE_H
#include "Instruction.h"
#include "Expression.h"


class InstructionEcrire : public Instruction {

public:
	InstructionEcrire(Expression *e);
	InstructionEcrire():Instruction(Identifiants::ID_INSTRUCTIONECRIRE){est_vide = true;}
	virtual ~InstructionEcrire(){}
	
	vector<Id*> getIds();
	Expression* getExpression(){return expression;}
	void setExpression();
	void transformation(vector<pair<Id*,Nombre*> > constantes);
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();

private:
	Expression *expression;

};


#endif 
