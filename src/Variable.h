#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Expression.h"

class Variable : public Expression {

public:
	Variable(string n);
	Variable():Expression(Identifiants::ID_VARIABLE){}
	virtual ~Variable(){}
	
	string getNom();
	virtual double eval(map<string,double> &mapV);	

private:
	string nom;

};


#endif 