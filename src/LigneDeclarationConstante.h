#if !defined ( LIGNE_DECLARATION_CONSTANTE_H )
#define LIGNE_DECLARATION_CONSTANTE_H

#include "Declaration.h"
#include "Id.h"
#include "Nombre.h"
#include "DeclarationConstante.h"

class LigneDeclarationConstante : public Declaration
{
	public:
		LigneDeclarationConstante(Id*, DeclarationConstante*, Nombre*);
		~LigneDeclarationConstante();
		vector<Id*> getConstantes();
		vector<Id*> getVariables();
		vector<pair<Id*,Nombre*> > getConstantesValeurs();

	protected:
		Id *id;
		DeclarationConstante *declarationConstante;
		Nombre *val;
};

#endif
