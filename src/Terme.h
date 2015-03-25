#if !defined ( TERME_H )
#define TERME_H
#include "Expression.h"

class Terme : public Expression {

public:
	Terme();
	Terme(int id):Expression(id){}
	virtual ~Terme(){}
	
	virtual double eval(map<string,double> &mapV){}

};


#endif 