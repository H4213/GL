#if !defined ( SOUSTRACTION_H )
#define SOUSTRACTION_H
#include "OperationAdditive.h"

class Soustraction : public OperationAdditive{

public:
	Soustraction();
	virtual ~Soustraction(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};


#endif 
