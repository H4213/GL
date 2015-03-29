#include "ExpressionParenthesee.h"

ExpressionParenthesee::ExpressionParenthesee(Expression *exp):Facteur(Identifiants::ID_EXPRESSIONPARENTHESEE)
{
	expression = exp;
	_symbole_string = "ExpressionParenthesee";
}

double ExpressionParenthesee::eval(map<string,double> &mapV , map<string,double> &mapC)
{
	double d = expression->eval(mapV,mapC);
	return d;
}

vector<Id*> ExpressionParenthesee::getIds()
{
	return expression->getIds();
}
