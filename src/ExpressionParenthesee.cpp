#include "ExpressionParenthesee.h"

ExpressionParenthesee::ExpressionParenthesee(Expression *exp):Expression(Identifiants::ID_EXPRESSIONPARENTHESEE)
{
	expression = exp;
	_symbole_string = "ExpressionParenthesee";
}

double ExpressionParenthesee::eval(map<string,double> &mapV)
{
	double d = expression->eval(mapV);
	return d;
}