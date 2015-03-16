#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"

class PartieDeclarative : public Symbole {

public:
	PartieDeclarative(Declaration d, PartieDeclarative partD); //Voir de passer vector<Declaration> et faire constructeur recurssif...
	virtual ~PartieDeclarative(){}

private:
	Declaration declaration;
	PartieDeclarative sousPartieDeclarative;

};


#endif 