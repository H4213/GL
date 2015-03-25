#if !defined ( EXPRESSIONADDITIVE_H )
#define EXPRESSIONADDITIVE_H
#include "Expression.h"
#include "Terme.h"
#include "OperationAdditive.h"


class ExpressionAdditive : public Expression {

public:
	ExpressionAdditive(Expression *exp, Terme *t, OperationAdditive *op);
	ExpressionAdditive():Expression(Identifiants::ID_EXPRESSIONADDITIVE){est_vide = true;}
	virtual ~ExpressionAdditive(){}

	virtual double eval(map<string,double> &mapV);

private:
	Expression *expression;
	Expression *terme;
	OperationAdditive *operationAdditive;

};


#endif 