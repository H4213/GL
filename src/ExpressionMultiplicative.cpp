#include "ExpressionMultiplicative.h"

ExpressionMultiplicative::ExpressionMultiplicative(Expression *exp1, Expression *exp2, OperationMultiplicative *op):Expression(Identifiants::ID_EXPRESSIONMULTIPLICATIVE)
{
	expression1 = exp1;
	expression2 = exp2;
	operationMultiplicative = op;
	_symbole_string = "ExpressionMultiplicative";
}

double ExpressionMultiplicative::eval(map<string,double> &mapV)
{
	double d;
	double valeurExp1 = expression1->eval(mapV);
	double valeurExp2 = expression2->eval(mapV);

	switch(char(*operationMultiplicative))//tester cast to char
	{
		case '*':
			//tester
			d = valeurExp1 * valeurExp2;
		break;
		
		case '/':
			//tester
			if(valeurExp2 != 0)
			{
				d = valeurExp1 / valeurExp2;
			}
			else
			{
				// TODO: erreur (division par zero)
			}
		break;
	}

	return d;
}