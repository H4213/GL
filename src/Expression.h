#if !defined ( EXPRESSION_H )
#define EXPRESSION_H
#include "Symbole.h"


class Expression : public Symbole {

public:
	Expression();
	Expression(int id);
	virtual ~Expression(){}
	
	virtual void executer();
	virtual Expression Eval();

};


#endif 