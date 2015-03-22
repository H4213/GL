#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Expression.h"

#include <string>


class Variable : public Expression {

public:
	Variable(string n);
	Variable():Expression(Identifiants::ID_VARIABLE){}
	virtual ~Variable(){}
	
	virtual void executer(map<string,double> &mapV);
	// Expression Eval();
	string getNom();

private:
	string nom;

};


#endif 