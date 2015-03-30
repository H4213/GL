#if !defined ( MULTIPLICATION_H )
#define MULTIPLICATION_H
#include "OperationMultiplicative.h"

class Multiplication : public OperationMultiplicative{

public:
	Multiplication();
	virtual ~Multiplication(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};


#endif 
