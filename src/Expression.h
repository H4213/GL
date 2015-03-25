#if !defined ( EXPRESSION_H )
#define EXPRESSION_H
#include "Symbole.h"
#include "Id.h"
#include <vector>
class Expression : public Symbole {

public:
	Expression();
	Expression(int id):Symbole(id){}
	virtual ~Expression(){}
	
	virtual double eval(map<string,double> &mapV){}
	virtual vector<string> getIds(){}
};


#endif 
