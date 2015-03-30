#include "ExpressionParenthesee.h"
#include <iostream>
#include <sstream>
ExpressionParenthesee::ExpressionParenthesee(Expression *exp):Facteur(Identifiants::ID_EXPRESSIONPARENTHESEE)
{
	expression = exp;
	_symbole_string = "ExpressionParenthesee";
}


Expression* ExpressionParenthesee::transformation(map<string,double> constantes)
{
	Expression * expNouveau = expression->transformation(constantes);
	if (dynamic_cast<Nombre*> (expNouveau)!=NULL)
	{
	    double valeur = ((Nombre*)(expNouveau))->getValeur();
	    std::ostringstream strs;
		strs <<valeur;
		std::string str = strs.str();
	    Nombre * result = new Nombre(str);
	    return result;
	}
	else{
	ExpressionParenthesee * result = new ExpressionParenthesee(expNouveau);
	return result;
	}
}

double ExpressionParenthesee::eval(map<string,double> &mapV , map<string,double> &mapC)
{
	double d = expression->eval(mapV,mapC);
	return d;
}

vector<Id*> ExpressionParenthesee::getIds()
{
	return expression->getIds();
}

void ExpressionParenthesee::print()
{
	cout<<"(";
	expression->print();
	cout<<")";
}
