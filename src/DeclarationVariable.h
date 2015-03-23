#if !defined ( DECLARATIONVARIABLE_H )
#define DECLARATIONVARIABLE_H
#include "Declaration.h"
#include "Variable.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationVariable : public Declaration {

public:
	DeclarationVariable(string nomVariable, vector<string> autresVariables = vector<string>());
	DeclarationVariable():Declaration(Identifiants::ID_DECLARATIONVARIABLE){}
	virtual ~DeclarationVariable(){}
	
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Variable variable;
	DeclarationVariable *declarationAutreVariable;

	void resteDuTableau(vector<string> &autresVariables);
	void comptageVariables();

};


#endif