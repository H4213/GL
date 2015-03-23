#if !defined ( OPERATIONMULTIPLICATIVE_H )
#define OPERATIONMULTIPLICATIVE_H
#include "Symbole.h"

class OperationMultiplicative : public Symbole 
{

public:
	OperationMultiplicative(int id):Symbole(id){}
	OperationMultiplicative();
	virtual ~OperationMultiplicative(){}

	operator char() const {return _operation;}
	
	virtual void executer(map<string,double> &mapV){}

protected:
	char _operation;

};


#endif 