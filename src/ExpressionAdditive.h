#if !defined ( EXPRESSIONADDITIVE_H )
#define EXPRESSIONADDITIVE_H
#include "Symbole.h"
#include "Terme.h"
#include "Nombre.h"
#include "OperationAdditive.h"
#include "Identifiants.h"
#include "Addition.h"
#include "Soustraction.h"

class ExpressionAdditive : public Expression 
{

public:
	ExpressionAdditive(Expression *exp, Terme *t, OperationAdditive *opA);
	ExpressionAdditive():Expression(Identifiants::ID_EXPRESSIONADDITIVE){est_vide = true;}
	virtual ~ExpressionAdditive(){}
	
	vector<Id*> getIds();

	Expression* transformation(map<string,double> constantes);
	Expression* transformation(vector<pair<Id*,Nombre*> > constantes);
	virtual double eval(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();
	

private:
	Expression *expression;
	Expression *terme;
	OperationAdditive *operationAdditive;

};


#endif 
