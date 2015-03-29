#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Facteur.h"


class ExpressionParenthesee : public Facteur
{

public:
	ExpressionParenthesee(Expression *exp);
	ExpressionParenthesee():Facteur(Identifiants::ID_EXPRESSIONPARENTHESEE){est_vide = true;}
	virtual ~ExpressionParenthesee(){}
	
	vector<Id*> getIds();
	virtual double eval(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();

private:
	Expression *expression;

};


#endif 
