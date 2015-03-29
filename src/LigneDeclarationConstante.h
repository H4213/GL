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
		LigneDeclarationConstante():Declaration(Identifiants::ID_LIGNEDECLARATIONCONSTANTE){est_vide = true;}
		~LigneDeclarationConstante();
		
		vector<Id*> getConstantes();
		vector<Id*> getVariables();
		void executer(map<string,double> &mapV , map<string,double> &mapC);

	protected:
		Id *id;
		DeclarationConstante *declarationConstante;
		Nombre *val;
};

#endif
