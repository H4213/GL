#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Facteur.h"
#include "Nombre.h"


class ExpressionParenthesee : public Facteur
{

public:
	ExpressionParenthesee(Expression *exp);
	ExpressionParenthesee():Facteur(Identifiants::ID_EXPRESSIONPARENTHESEE){est_vide = true;}
	virtual ~ExpressionParenthesee(){}

	Expression* transformation(map<string,double> constantes);

	vector<Id*> getIds();
	virtual double eval(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();

private:
	Expression *expression;

};


#endif 
