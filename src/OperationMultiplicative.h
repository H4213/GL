#if !defined ( OPERATIONMULTIPLICATIVE_H )
#define OPERATIONMULTIPLICATIVE_H
#include "Symbole.h"
#include "Identifiants.h"

class OperationMultiplicative : public Symbole {

public:
	OperationMultiplicative():Symbole(Identifiants::ID_OPERATIONMULTIPLICATIVE){}
	OperationMultiplicative(int id):Symbole(id){}
	virtual ~OperationMultiplicative(){}

};


#endif 