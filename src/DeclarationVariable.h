#if !defined ( DECLARATIONVARIABLE_H )
#define DECLARATIONVARIABLE_H
#include "Declaration.h"
#include "Id.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationVariable : public Declaration {

public:
	DeclarationVariable(Id *id, DeclarationVariable *dV = new DeclarationVariable());
	DeclarationVariable():Declaration(Identifiants::ID_DECLARATIONVARIABLE){est_vide = true;}
	virtual ~DeclarationVariable(){}
	
	Id* getId(){return id;}
	DeclarationVariable* getDeclarationVariable(){return declarationAutreVariable;}
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Id *id;
	DeclarationVariable *declarationAutreVariable;

	void compterVariables();

};


#endif