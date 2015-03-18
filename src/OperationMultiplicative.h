#if !defined ( OPERATIONMULTIPLICATIVE_H )
#define OPERATIONMULTIPLICATIVE_H
#include "Symbole.h"


class OperationMultiplicative : public Symbole {

public:
	OperationMultiplicative();
	OperationMultiplicative(int id):Symbole(id){}
	virtual ~OperationMultiplicative(){}

};


#endif 