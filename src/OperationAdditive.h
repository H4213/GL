#if !defined ( OPERATIONADDITIVE_H )
#define OPERATIONADDITIVE_H
#include "Symbole.h"

class OperationAdditive : public Symbole 
{

public:
	OperationAdditive(int id):Symbole(id){}
	OperationAdditive();
	virtual ~OperationAdditive(){}

	operator char() const {return _operation;}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

protected:
	char _operation;

};


#endif 