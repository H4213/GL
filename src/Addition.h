#if !defined ( ADDITION_H )
#define ADDITION_H
#include "Symbole.h"
#include "OperationAdditive.h"

class Addition : public Symbole,  public OperationAdditive {

public:
	Addition();
	virtual ~Addition(){}

};


#endif 
