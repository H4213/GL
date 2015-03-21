#if !defined ( DIVISION_H )
#define DIVISION_H
#include "Symbole.h"
#include "OperationMultiplicative.h"

class Division : public OperationMultiplicative{

public:
	Division();
	virtual ~Division(){}
	
	virtual void executer();

};

#endif 
