#include "ExpressionAdditive.h"
#include "Identifiants.h"

#include <string>

ExpressionAdditive::ExpressionAdditive(Expression exp1, Expression exp2, OperationAdditive op):Expression(Identifiants::ID_EXPRESSIONADDITIVE)
{
	expression1 = exp1;
	expression2 = exp2;
	operationAdditive = op;
	_symbole_string = "ExpressionAdditive";
}