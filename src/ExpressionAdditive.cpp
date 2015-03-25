#include "ExpressionAdditive.h"
	
#include <iostream>

ExpressionAdditive::ExpressionAdditive(Expression *e, Terme *t, OperationAdditive *op):Expression(Identifiants::ID_EXPRESSIONADDITIVE)
{
	expression = e;
	terme = t;
	operationAdditive = op;
	_symbole_string = "ExpressionAdditive";
}

double ExpressionAdditive::eval(map<string,double> &mapV)
{
	double d;
	double valeurExp = expression->eval(mapV);
	double valeurTerme = terme->eval(mapV);

	switch(char(*operationAdditive))
	{
		cout<<"dentro do switch"<<endl;
		case '+':
			d = valeurExp + valeurTerme;
		break;
		case '-':
			d = valeurExp - valeurTerme;
		break;
	}

	return d;
}