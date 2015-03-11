#if !defined ( MULTIPLICATION_H )
#define MULTIPLICATION_H
#include "Symbole.h"
#include "OperationMultiplicative.h"

class Multiplication : public Symbole, public OperationMultiplicative{

public:
	Multiplication();
	virtual ~Multiplication(){}

};


#endif 
