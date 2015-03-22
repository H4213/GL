#if !defined ( ADDITION_H )
#define ADDITION_H
#include "Symbole.h"
#include "OperationAdditive.h"

class Addition : public OperationAdditive {

public:
	Addition();
	virtual ~Addition(){}

	void executer(map<string,double> &mapV){}

};


#endif 
