#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Expression.h"


class Variable : public Expression {

public:
	Variable();
	virtual ~Variable(){}

};


#endif 