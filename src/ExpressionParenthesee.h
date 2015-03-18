#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Expression.h"


class ExpressionParenthesee : public Expression {

public:
	ExpressionParenthesee(Expression exp);
	virtual ~ExpressionParenthesee(){}

private:
	Expression expression;

};


#endif 