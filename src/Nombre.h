#if !defined ( NOMBRE_H )
#define NOMBRE_H
#include "Expression.h"

#include <string>


class Nombre : public Expression {

public:
	Nombre(double v);
	Nombre():Expression(Identifiants::ID_NOMBRE){}
	virtual ~Nombre(){}
	
	virtual void executer(map<string,double> &mapV){}
	Expression Eval();

private:
	double valeur;

};


#endif 