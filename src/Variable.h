#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Expression.h"

#include <string>


class Variable : public Expression {

public:
	Variable(string n);
	Variable(){}
	virtual ~Variable(){}

private:
	string nom;

};


#endif 