#if !defined ( EXPRESSION_H )
#define EXPRESSION_H
#include <vector>
#include "Symbole.h"

class Id;
class Expression : public Symbole {

public:
	Expression();
	Expression(int id):Symbole(id){}
	virtual ~Expression(){}
	virtual vector<Id*> getIds();
	virtual double eval(map<string,double> &mapV){}

};


#endif