#if !defined ( LIGNE_DECLARATION_VARIABLE_H )
#define LIGNE_DECLARATION_VARIABLE_H

#include "Declaration.h"
#include "DeclarationVariable.h"
#include "Id.h"
#include "Nombre.h"


class LigneDeclarationVariable : public Declaration
{
	public:
		LigneDeclarationVariable(Id*, DeclarationVariable*);
		~LigneDeclarationVariable();
		vector<Id*> getVariables();
		vector<Id*> getConstantes();


		vector<pair<Id*,Nombre*> > getConstantesValeurs();

        void executer(map<string,double> &mapV);

		Id *id;
		DeclarationVariable *declarationVariable;

};

#endif
