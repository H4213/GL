#if !defined ( OPERATIONADDITIVE_H )
#define OPERATIONADDITIVE_H
#include "Symbole.h"

class OperationAdditive : public Symbole {

public:
	OperationAdditive(int id):Symbole(id){}
	OperationAdditive();
	virtual ~OperationAdditive(){}
	
	virtual void executer(map<string,double> &mapV){}

};


#endif 