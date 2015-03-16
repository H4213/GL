#if !defined ( OPERATIONADDITIVE_H )
#define OPERATIONADDITIVE_H
#include "Symbole.h"


class OperationAdditive : public Symbole {

public:
	OperationAdditive();
	OperationAdditive(int id):Symbole(id){}
	virtual ~OperationAdditive(){}

};


#endif 