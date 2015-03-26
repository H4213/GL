#include "ExpressionMultiplicative.h"

ExpressionMultiplicative::ExpressionMultiplicative(Terme *t, Facteur *f, OperationMultiplicative *opM):Terme(Identifiants::ID_EXPRESSIONMULTIPLICATIVE)
{
	terme = t;
	facteur = f;
	operationMultiplicative = opM;
	_symbole_string = "ExpressionMultiplicative";
}

double ExpressionMultiplicative::eval(map<string,double> &mapV)
{
	double d;
	double valeurTerme = terme->eval(mapV);
	double valeurFacteur = facteur->eval(mapV);

	switch(char(*operationMultiplicative))//tester cast to char
	{
		case '*':
			//tester
			d = valeurTerme * valeurFacteur;
		break;
		
		case '/':
			//tester
			/*if(valeurExp2 != 0)
			{
				d = valeurTerme / valeurFacteur;
			}
			else
			{
				// TODO: erreur (division par zero)
			}*/
		break;
	}

	return d;
}
