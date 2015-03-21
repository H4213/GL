#if !defined ( DECLARATIONVARIABLE_H )
#define DECLARATIONVARIABLE_H
#include "Declaration.h"
#include "Variable.h"
#include "Identifiants.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationVariable : public Declaration {

public:
	DeclarationVariable(string nomVariable, vector<string> autresVariables);
	DeclarationVariable():Declaration(Identifiants::ID_DECLARATIONVARIABLE){}
	virtual ~DeclarationVariable(){}
	
	virtual void executer();
	void comptageVariables();
	void print();

private:
	Variable variable;
	DeclarationVariable *declarationAutreVariable;

	void resteDuTableau(vector<string> &autresVariables);

};


#endif