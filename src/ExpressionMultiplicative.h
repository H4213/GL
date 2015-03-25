#if !defined ( EXPRESSIONMULTIPLICATIVE_H )
#define EXPRESSIONMULTIPLICATIVE_H
#include "Expression.h"
#include "OperationMultiplicative.h"
#include <vector>

class ExpressionMultiplicative : public Expression {

public:
	ExpressionMultiplicative(Expression *exp1, Expression *exp2, OperationMultiplicative *op);
	ExpressionMultiplicative():Expression(Identifiants::ID_EXPRESSIONMULTIPLICATIVE){}
	virtual ~ExpressionMultiplicative(){}

	virtual double eval(map<string,double> &mapV);
	
	vector<string> getIds();

private:
	Expression *expression1;
	Expression *expression2;
	OperationMultiplicative *operationMultiplicative;
};


#endif 
