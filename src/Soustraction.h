#if !defined ( SOUSTRACTION_H )
#define SOUSTRACTION_H
#include "Symbole.h"
#include "OperationAdditive.h"

class Soustraction : public Symbole, public OperationAdditive{

public:
	Soustraction();
	virtual ~Soustraction(){}

};


#endif 
