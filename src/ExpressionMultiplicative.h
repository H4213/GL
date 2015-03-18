#if !defined ( EXPRESSIONMULTIPLICATIVE_H )
#define EXPRESSIONMULTIPLICATIVE_H
#include "Expression.h"
#include "OperationMultiplicative.h"


class ExpressionMultiplicative : public Expression {

public:
	ExpressionMultiplicative(Expression exp1, Expression exp2, OperationMultiplicative op);
	virtual ~ExpressionMultiplicative(){}

private:
	Expression expression1;
	Expression expression2;
	OperationMultiplicative operationMultiplicative;
};


#endif 