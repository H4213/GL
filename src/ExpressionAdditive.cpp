#include "ExpressionAdditive.h"
	
#include <iostream>
#include <sstream>
ExpressionAdditive::ExpressionAdditive(Expression *e, Terme *t, OperationAdditive *opA):Expression(Identifiants::ID_EXPRESSIONADDITIVE)
{
	expression = e;
	terme = t;
	operationAdditive = opA;
	_symbole_string = "ExpressionAdditive";
}

Expression* ExpressionAdditive::transformation(map<string,double> constantes)
{
	Expression * newExpression=expression->transformation(constantes);
	Terme * newTerme=(Terme*)terme->transformation(constantes);
	OperationAdditive * newOpA;
	if ((char) *operationAdditive =='+')
	{
	newOpA=new Addition();
	}
	else if((char) *operationAdditive =='-')
	{
	newOpA=new Soustraction();
	}
	double valeur1;
	double valeur2;
	
	if ((int) *newTerme ==Identifiants::ID_NOMBRE)
	{
		valeur2=((Nombre*)terme)->getValeur();
		if (valeur2==0)
		{
			return newExpression;
		}
	}
	if ((int) *newExpression ==Identifiants::ID_NOMBRE)
	{
		valeur1=((Nombre*)newExpression)->getValeur();
		if (valeur1==0)
		{
			return newTerme ;
		}
	}
	if ((int) *newExpression ==Identifiants::ID_NOMBRE && (int) *newTerme ==Identifiants::ID_NOMBRE )
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
		ExpressionAdditive * exprRes = new ExpressionAdditive(newExpression,newTerme,newOpA);
		return exprRes;
	}
}
vector<Id*> ExpressionAdditive::getIds()
{
	vector<Id*> resultat = expression->getIds();
	vector<Id*> temp = terme->getIds();
	resultat.insert(resultat.end(),temp.begin(),temp.end());
	return resultat;
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
