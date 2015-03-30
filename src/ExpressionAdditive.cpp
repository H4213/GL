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
	double valeur1;
	double valeur2;
	if ((char) *operationAdditive =='+')
	{
	newOpA=new Addition();
		if (dynamic_cast<Nombre*> (newTerme)!=NULL)
        {

            valeur2=((Nombre*)newTerme)->getValeur();
            if (valeur2==0)
            {
                return newExpression;
            }
        }
        if (dynamic_cast<Nombre*> (newExpression)!=NULL)
        {


            valeur1=((Nombre*)newExpression)->getValeur();
            if (valeur1==0)
            {
                return newTerme ;
            }
        }
        if (dynamic_cast<Nombre*> (newExpression)!=NULL && dynamic_cast<Nombre*> (newTerme)!=NULL )
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
	else if((char) *operationAdditive =='-')
	{
	newOpA=new Soustraction();
		if (dynamic_cast<Nombre*> (newTerme)!=NULL)
        {

            valeur2=((Nombre*)newTerme)->getValeur();
            if (valeur2==0)
            {
                return newExpression;
            }
        }
        if (dynamic_cast<Nombre*> (newExpression)!=NULL)
        {


            valeur1=((Nombre*)newExpression)->getValeur();

        }
        if (dynamic_cast<Nombre*> (newExpression)!=NULL && dynamic_cast<Nombre*> (newTerme)!=NULL )
        {
            double valeur3=valeur1-valeur2;
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

void ExpressionAdditive::print()
{
	expression->print();
	operationAdditive->print();
	terme->print();
}
