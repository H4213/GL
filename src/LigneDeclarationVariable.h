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
<<<<<<< HEAD

		vector<pair<Id*,Nombre*> > getConstantesValeurs();

        void executer(map<string,double> &mapV);

=======
        void executer(map<string,double> &mapV);
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
	protected:
		Id *id;
		DeclarationVariable *declarationVariable;

};

#endif
