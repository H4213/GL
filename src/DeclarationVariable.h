#if !defined ( DECLARATIONVARIABLE_H )
#define DECLARATIONVARIABLE_H
#include "Declaration.h"
#include "Variable.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationVariable : public Declaration {

public:
	DeclarationVariable(string nomVariable, vector<string> autresVariables); 
	virtual ~DeclarationVariable(){}

	vector<string> resteDuTableau(vector<string> autresVariables);
	void print();

private:
	Variable variable;
	DeclarationVariable* declarationAutreVariable;

};


#endif