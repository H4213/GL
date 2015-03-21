#if !defined ( EXPRESSIONMULTIPLICATIVE_H )
#define EXPRESSIONMULTIPLICATIVE_H
#include "Expression.h"
#include "OperationMultiplicative.h"
#include "Identifiants.h"

class ExpressionMultiplicative : public Expression {

public:
	ExpressionMultiplicative(Expression *exp1, Expression *exp2, OperationMultiplicative *op);
	ExpressionMultiplicative():Expression(Identifiants::ID_EXPRESSIONMULTIPLICATIVE){}
	virtual ~ExpressionMultiplicative(){}

	virtual void executer();
	Expression Eval();

private:
	Expression *expression1;
	Expression *expression2;
	OperationMultiplicative *operationMultiplicative;
};


#endif 