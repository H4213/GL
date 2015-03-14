#if !defined ( DECLARATIONVARIABLE_H )
#define DECLARATIONVARIABLE_H
#include "Declaration.h"
#include "Variable.h"

#include <string>

class DeclarationVariable : public Declaration {

public:
	DeclarationVariable(string nomVariable); //peut etre, aussi, un tableau de string pour creer recoursivement les autres declarations variables
	virtual ~DeclarationVariable(){}

private:
	Variable var;
	DeclarationVariable declarationAutreVariable;

};


#endif