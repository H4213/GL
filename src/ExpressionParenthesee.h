#if !defined ( EXPRESSIONPARENTHESEE_H )
#define EXPRESSIONPARENTHESEE_H
#include "Facteur.h"


class FacteurParenthesee : public Facteur {

public:
	FacteurParenthesee(Facteur *exp);
	FacteurParenthesee():Facteur(Identifiants::ID_EXPRESSIONPARENTHESEE){est_vide = true;}
	virtual ~FacteurParenthesee(){}

	virtual double eval(map<string,double> &mapV);

private:
	Facteur *expression;

};


#endif 