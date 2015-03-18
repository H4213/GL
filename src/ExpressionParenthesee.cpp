#include "ExpressionParenthesee.h"
#include "Identifiants.h"

#include <string>

ExpressionParenthesee::ExpressionParenthesee(Expression exp):Expression(Identifiants::ID_EXPRESSIONPARENTHESEE)
{
	expression = exp;
	_symbole_string = "ExpressionParenthesee";
}