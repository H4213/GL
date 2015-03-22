#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Expression.h"


class ExpressionParenthesee : public Expression {

public:
	ExpressionParenthesee(Expression *exp);
	ExpressionParenthesee():Expression(Identifiants::ID_EXPRESSIONPARENTHESEE){}
	virtual ~ExpressionParenthesee(){}

	virtual void executer(map<string,double> &mapV){}
	Expression Eval();

private:
	Expression *expression;

};


#endif 