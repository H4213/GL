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
	protected:
		Id *id;
		DeclarationConstante *declarationConstante;
		Nombre *val;
};

#endif