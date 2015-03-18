#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Expression.h"
#include "Identifiants.h"


class ExpressionParenthesee : public Expression {

public:
	ExpressionParenthesee(Expression exp);
	ExpressionParenthesee():Expression(Identifiants::ID_EXPRESSIONPARENTHESEE){}
	virtual ~ExpressionParenthesee(){}

private:
	Expression expression;

};


#endif 