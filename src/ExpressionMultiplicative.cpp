#include "ExpressionMultiplicative.h"
#include "Identifiants.h"

#include <string>

ExpressionMultiplicative::ExpressionMultiplicative(Expression *exp1, Expression *exp2, OperationMultiplicative *op):Expression(Identifiants::ID_EXPRESSIONMULTIPLICATIVE)
{
	expression1 = exp1;
	expression2 = exp2;
	operationMultiplicative = op;
	_symbole_string = "ExpressionMultiplicative";
}