#if !defined ( EXPRESSIONADDITIVE_H )
#define EXPRESSIONADDITIVE_H
#include "Expression.h"
#include "OperationAdditive.h"
#include "Identifiants.h"


class ExpressionAdditive : public Expression {

public:
	ExpressionAdditive(Expression *exp1, Expression *exp2, OperationAdditive *op);
	ExpressionAdditive():Expression(Identifiants::ID_EXPRESSIONADDITIVE){}
	virtual ~ExpressionAdditive(){}

	
	virtual void executer();
	Expression Eval();

private:
	Expression *expression1;
	Expression *expression2;
	OperationAdditive *operationAdditive;

};


#endif 