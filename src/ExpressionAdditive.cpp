#include "ExpressionAdditive.h"
	
#include <iostream>

ExpressionAdditive::ExpressionAdditive(Expression *e, Terme *t, OperationAdditive *opA):Expression(Identifiants::ID_EXPRESSIONADDITIVE)
{
	expression = e;
	terme = t;
	operationAdditive = opA;
	_symbole_string = "ExpressionAdditive";
}

vector<Id*> ExpressionAdditive::getIds()
{
	vector<Id*> resultat = expression->getIds();
	vector<Id*> temp = terme->getIds();
	resultat.insert(resultat.end(),temp.begin(),temp.end());
	return resultat;
}

double ExpressionAdditive::eval(map<string,double> &mapV , map<string,double> &mapC)
{
	double d;
	double valeurExp = expression->eval(mapV,mapC);
	double valeurTerme = terme->eval(mapV,mapC);

	switch(char(*operationAdditive))
	{
		case '+':
			d = valeurExp + valeurTerme;
		break;
		case '-':
			d = valeurExp - valeurTerme;
		break;
	}

	return d;
}
