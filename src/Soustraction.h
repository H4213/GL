#if !defined ( SOUSTRACTION_H )
#define SOUSTRACTION_H
#include "Symbole.h"
#include "OperationAdditive.h"

class Soustraction : public OperationAdditive{

public:
	Soustraction();
	virtual ~Soustraction(){}
	
	virtual void executer();

};


#endif 
