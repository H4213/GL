#if !defined ( DECLARATIONVARIABLE_H )
#define DECLARATIONVARIABLE_H
#include "Declaration.h"
#include "Variable.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationVariable : public Declaration {

public:
	DeclarationVariable(Variable *v, DeclarationVariable *dV = new DeclarationVariable());
	DeclarationVariable():Declaration(Identifiants::ID_DECLARATIONVARIABLE){est_vide = true;}
	virtual ~DeclarationVariable(){}
	
	Variable* getVariable(){return variable;}
	DeclarationVariable* getDeclarationVariable(){return declarationAutreVariable;}
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Variable *variable;
	DeclarationVariable *declarationAutreVariable;

	void compterVariables();

};


#endif