#include "ExpressionParenthesee.h"

ExpressionParenthesee::ExpressionParenthesee(Expression *exp):Facteur(Identifiants::ID_EXPRESSIONPARENTHESEE)
{
	expression = exp;
	_symbole_string = "ExpressionParenthesee";
}

Expression* ExpressionParenthesee::transformation(map<string,double> constantes)
{
	Expression * expNouveau = expression->transformation(constantes);
	ExpressionParenthesee * result = new ExpressionParenthesee(expNouveau);
	return result;
}
double ExpressionParenthesee::eval(map<string,double> &mapV)
{
	double d = expression->eval(mapV);
	return d;
}
vector<Id*> ExpressionParenthesee::getIds()
{
	return expression->getIds();
}
