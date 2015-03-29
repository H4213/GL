#include "ExpressionMultiplicative.h"

ExpressionMultiplicative::ExpressionMultiplicative(Terme *t, Facteur *f, OperationMultiplicative *opM):Terme(Identifiants::ID_EXPRESSIONMULTIPLICATIVE)
{
	terme = t;
	facteur = f;
	operationMultiplicative = opM;
	_symbole_string = "ExpressionMultiplicative";
}
vector<Id*> ExpressionMultiplicative::getIds()
{
	vector<Id*> result = terme->getIds();
	vector<Id*> temp =facteur->getIds();
	result.insert(result.end(),temp.begin(),temp.end());
	return result;
}
double ExpressionMultiplicative::eval(map<string,double> &mapV , map<string,double> &mapC)
{
	double d;
	double valeurTerme = terme->eval(mapV,mapC);
	double valeurFacteur = facteur->eval(mapV,mapC);

	switch(char(*operationMultiplicative))
	{
		case '*':
			d = valeurTerme * valeurFacteur;
		break;

		case '/':
			if(valeurFacteur != 0)
			{
				d = valeurTerme / valeurFacteur;
			}
			else
			{
				// TODO: erreur (division par zero)
			}
		break;
	}
	return d;
}

void ExpressionMultiplicative::print()
{
	terme->print();
	operationMultiplicative->print();
	facteur->print();
}
