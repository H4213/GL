#if !defined ( OPERATIONMULTIPLICATIVE_H )
#define OPERATIONMULTIPLICATIVE_H
#include "Symbole.h"
#include "Identifiants.h"

class OperationMultiplicative : public Symbole {

public:
	OperationMultiplicative(int id):Symbole(id){}
	OperationMultiplicative();
	virtual ~OperationMultiplicative(){}
	
	virtual void executer();

};


#endif 