#if !defined ( ADDITION_H )
#define ADDITION_H
#include "Symbole.h"
#include "OperationAdditive.h"

class Addition : public OperationAdditive {

public:
	Addition();
	virtual ~Addition(){}

	virtual void executer(){}

};


#endif 
