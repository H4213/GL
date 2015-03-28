#if !defined ( LIGNE_DECLARATION_VARIABLE_H )
#define LIGNE_DECLARATION_VARIABLE_H

#include "Declaration.h"
#include "DeclarationVariable.h"
#include "Id.h"

class LigneDeclarationVariable : public Declaration
{
	public:
		LigneDeclarationVariable(Id*, DeclarationVariable*);
		~LigneDeclarationVariable();
		vector<Id*> getVariables();
		vector<Id*> getConstantes();
	protected:
		Id *id;
		DeclarationVariable *declarationVariable;

};

#endif
