#if !defined ( OPERATIONMULTIPLICATIVE_H )
#define OPERATIONMULTIPLICATIVE_H
#include "Symbole.h"

class OperationMultiplicative : public Symbole {

public:
	OperationMultiplicative(int id):Symbole(id){}
	OperationMultiplicative();
	virtual ~OperationMultiplicative(){}
	
	virtual void executer(map<string,double> &mapV){}

};


#endif 