#if !defined ( TERME_H )
#define TERME_H
#include "Expression.h"
#include "Id.h"
class Terme : public Expression 
{

public:
	Terme();
	Terme(int id):Expression(id){}
	virtual ~Terme(){}
	virtual vector<Id*> getIds();
	virtual double eval(map<string,double> &mapV){}

};


#endif 
