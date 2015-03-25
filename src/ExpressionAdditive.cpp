#include "ExpressionAdditive.h"
	
#include <iostream>

ExpressionAdditive::ExpressionAdditive(Expression *exp1, Expression *exp2, OperationAdditive *op):Expression(Identifiants::ID_EXPRESSIONADDITIVE)
{
	expression1 = exp1;
	expression2 = exp2;
	operationAdditive = op;
	_symbole_string = "ExpressionAdditive";
}

double ExpressionAdditive::eval(map<string,double> &mapV)
{
	double d;
	double valeurExp1 = expression1->eval(mapV);
	double valeurExp2 = expression2->eval(mapV);

	switch(char(*operationAdditive))
	{
		cout<<"dentro do switch"<<endl;
		case '+':
			d = valeurExp1 + valeurExp2;
		break;
		case '-':
			d = valeurExp1 - valeurExp2;
		break;
	}

	return d;
}

vector <string> ExpressionAdditive::getIds()
{
	vector<string> temp1=expression1->getIds();
	vector<string> temp2=expression2->getIds();
	temp1.insert(temp1.end(),temp2.begin(),temp2.end());
	return temp1;
}
