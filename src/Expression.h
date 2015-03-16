#if !defined ( EXPRESSION_H )
#define EXPRESSION_H
#include "Symbole.h"


class Expression : public Symbole {

public:
	Expression();
	Expression(int id);
	virtual ~Expression(){}

	virtual double Eval();

};


#endif 