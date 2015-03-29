#if !defined ( LIGNE_DECLARATION_VARIABLE_H )
#define LIGNE_DECLARATION_VARIABLE_H

#include "Declaration.h"
#include "DeclarationVariable.h"
#include "Id.h"

class LigneDeclarationVariable : public Declaration
{
	public:
		LigneDeclarationVariable(Id* i, DeclarationVariable* dv = new DeclarationVariable());
		LigneDeclarationVariable():Declaration(Identifiants::ID_LIGNEDECLARATIONVARIABLE){est_vide = true;}
		~LigneDeclarationVariable();
		
		vector<Id*> getVariables();
		vector<Id*> getConstantes();
        virtual void executer(map<string,double> &mapV , map<string,double> &mapC);
        virtual void print();

	protected:
		Id *id;
		DeclarationVariable *declarationVariable;

};

#endif
