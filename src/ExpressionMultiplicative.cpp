#include "ExpressionMultiplicative.h"
#include <sstream>
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
Expression* ExpressionMultiplicative::transformation(map<string,double> constantes)
{
	Terme * newTerme=(Terme*)(terme->transformation(constantes));
	Facteur * newFacteur=(Facteur*)(facteur->transformation(constantes));
	OperationMultiplicative * newOpM;
	if ((char) *operationMultiplicative =='*')
	{
	newOpM=new Multiplication();
	}
	else if((char) *operationMultiplicative =='-')
	{
	newOpM=new Division();
	}
	double valeur1;
	double valeur2;
	
	if ((int) *newTerme ==Identifiants::ID_NOMBRE)
	{
		valeur1=((Nombre*)newTerme)->getValeur();
		if (valeur1==1)
		{
			return newFacteur;
		}
	}
	if ((int) *newFacteur ==Identifiants::ID_NOMBRE)
	{
		valeur2=((Nombre*)newFacteur)->getValeur();
		if (valeur2==1)
		{
			return newTerme ;
		}
	}
	if ((int) *newTerme ==Identifiants::ID_NOMBRE && (int) *newFacteur ==Identifiants::ID_NOMBRE )
	{
		double valeur3=valeur1+valeur2;
		std::ostringstream strs;
		strs <<valeur3;
		std::string str = strs.str();
		Nombre * nombreRes=new Nombre(str);
		return nombreRes;
	}
	else
	{
		ExpressionMultiplicative * exprRes = new ExpressionMultiplicative(newTerme,newFacteur,newOpM);
		return exprRes;
	}
}
