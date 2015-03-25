#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Expression.h"


class ExpressionParenthesee : public Expression {

public:
	ExpressionParenthesee(Expression *exp);
	ExpressionParenthesee():Expression(Identifiants::ID_EXPRESSIONPARENTHESEE){}
	virtual ~ExpressionParenthesee(){}

	virtual double eval(map<string,double> &mapV);
	vector<string> getIds();
private:
	Expression *expression;

};


#endif 
