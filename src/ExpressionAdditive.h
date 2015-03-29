#if !defined ( EXPRESSIONADDITIVE_H )
#define EXPRESSIONADDITIVE_H
#include "Expression.h"
#include "Terme.h"
#include "OperationAdditive.h"


class ExpressionAdditive : public Expression 
{

public:
	ExpressionAdditive(Expression *exp, Terme *t, OperationAdditive *opA);
	ExpressionAdditive():Expression(Identifiants::ID_EXPRESSIONADDITIVE){est_vide = true;}
	virtual ~ExpressionAdditive(){}
	
	vector<Id*> getIds();
	virtual double eval(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();

private:
	Expression *expression;
	Expression *terme;
	OperationAdditive *operationAdditive;

};


#endif 
