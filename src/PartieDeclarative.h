#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"
#include "Identifiants.h"

class PartieDeclarative : public Symbole {

public:
	PartieDeclarative(Declaration d, PartieDeclarative* partieD); //Voir de passer vector<Declaration> et faire constructeur recurssif...
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){}
	virtual ~PartieDeclarative(){}

private:
	Declaration declaration;
	PartieDeclarative* sousPartieDeclarative;

};


#endif 