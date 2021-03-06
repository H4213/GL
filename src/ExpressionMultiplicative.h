#if !defined ( EXPRESSIONMULTIPLICATIVE_H )
#define EXPRESSIONMULTIPLICATIVE_H

#include "OperationMultiplicative.h"
#include "Division.h"
#include "Multiplication.h"
#include "Nombre.h"
#include "Terme.h"
#include "Facteur.h"

class ExpressionMultiplicative : public Terme {

public:
	ExpressionMultiplicative(Terme *t, Facteur *f, OperationMultiplicative *opM);
	ExpressionMultiplicative():Terme(Identifiants::ID_EXPRESSIONMULTIPLICATIVE){est_vide = true;}
	virtual ~ExpressionMultiplicative(){}
	
	vector<Id*> getIds();

	Expression* transformation(map<string,double> constantes);

	virtual double eval(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();


private:
	Terme *terme;
	Facteur *facteur;
	OperationMultiplicative *operationMultiplicative;
};


#endif 
