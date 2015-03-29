#include "ExpressionAdditive.h"
	
#include <iostream>

ExpressionAdditive::ExpressionAdditive(Expression *e, Terme *t, OperationAdditive *opA):Expression(Identifiants::ID_EXPRESSIONADDITIVE)
{
	expression = e;
	terme = t;
	operationAdditive = opA;
	_symbole_string = "ExpressionAdditive";
}

Expression* ExpressionAdditive::transformation(map<Id*,Nombre*> > constantes)
{
	expression=expression->transformation(vector<pair<Id*,Nombre*> > constantes);
	terme=terme->transformation(map<Id*,Nombre*> > constantes);
	double valeur1;
	double valeur2;
	if ((int) terme ==identifiants::ID_NOMBRE)
	{
		valeur2=terme->getValeur();
	}
	if ((int) expression ==identifiants::ID_NOMBRE)
	{
		valeur1=expression->getValeur();
	}
	if ((int) terme ==identifiants::ID_ID)
	{
		if(std::find(constantes.begin(),constantes.end()
		valeur2=terme->getValeur();
	}
	if ((int) expression ==identifiants::ID_ID)
	{
		valeur1=terme->getValeur();
	}
	if ((int) expression==identifiants::ID_NOMBRE && (int) terme==identifiants::ID_NOMBRE)
	{
		terme
		Nombre* nb = 
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
