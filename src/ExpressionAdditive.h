#if !defined ( EXPRESSIONADDITIVE_H )
#define EXPRESSIONADDITIVE_H
#include "Expression.h"
#include "OperationAdditive.h"
#include <vector>

class ExpressionAdditive : public Expression {

public:
	ExpressionAdditive(Expression *exp1, Expression *exp2, OperationAdditive *op);
	ExpressionAdditive():Expression(Identifiants::ID_EXPRESSIONADDITIVE){}
	virtual ~ExpressionAdditive(){}

	virtual double eval(map<string,double> &mapV);

	vector<string> getIds();
private:
	Expression *expression1;
	Expression *expression2;
	OperationAdditive *operationAdditive;

};


#endif 
