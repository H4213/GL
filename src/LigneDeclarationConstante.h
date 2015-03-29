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
		void executer(map<string,double> &mapV);

		vector<pair<Id*,Nombre*> > getConstantesValeurs();

		void executer(map<string,double> &mapV);

	protected:
		Id *id;
		DeclarationConstante *declarationConstante;
		Nombre *val;
};

#endif
