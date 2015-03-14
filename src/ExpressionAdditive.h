#if !defined ( EXPRESSIONADDITIVE_H )
#define EXPRESSIONADDITIVE_H
#include "Expression.h"
#include "OperationAdditive.h"


class ExpressionAdditive : public Expression {

public:
	ExpressionAdditive(Expression exp1, Expression exp2, OperationAdditive op);
	virtual ~ExpressionAdditive(){}

private:
	Expression expression1;
	Expression expression2;
	OperationAdditive operationAdditive;

};


#endif 