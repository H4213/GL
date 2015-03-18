#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Expression.h"
#include "Identifiants.h"

#include <string>


class Variable : public Expression {

public:
	Variable(string n);
	Variable():Expression(Identifiants::ID_VARIABLE){}
	virtual ~Variable(){}

private:
	string nom;

};


#endif 