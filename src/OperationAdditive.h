#if !defined ( OPERATIONADDITIVE_H )
#define OPERATIONADDITIVE_H
#include "Symbole.h"
#include "Identifiants.h"


class OperationAdditive : public Symbole {

public:
	OperationAdditive(int id):Symbole(id){}
	OperationAdditive():Symbole(Identifiants::ID_OPERATIONADDITIVE){}
	virtual ~OperationAdditive(){}

};


#endif 