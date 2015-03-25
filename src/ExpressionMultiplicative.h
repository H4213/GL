#if !defined ( EXPRESSIONMULTIPLICATIVE_H )
#define EXPRESSIONMULTIPLICATIVE_H
#include "Expression.h"
#include "OperationMultiplicative.h"
#include "Terme.h"
#include "Facteur.h"

class ExpressionMultiplicative : public Expression {

public:
	ExpressionMultiplicative(Terme *t, Facteur *f, OperationMultiplicative *opM);
	ExpressionMultiplicative():Expression(Identifiants::ID_EXPRESSIONMULTIPLICATIVE){est_vide = true;}
	virtual ~ExpressionMultiplicative(){}

	virtual double eval(map<string,double> &mapV);

private:
	Terme *terme;
	Facteur *facteur;
	OperationMultiplicative *operationMultiplicative;
};


#endif 