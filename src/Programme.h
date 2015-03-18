#if !defined ( PROGRAMME_H )
#define PROGRAMME_H
#include "Symbole.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Identifiants.h"


class Programme : public Symbole {

public:
	Programme(PartieDeclarative partieD, PartieInstructive partieI);
	Programme():Symbole(Identifiants::ID_PROGRAMME){}
	virtual ~Programme(){} //TODO: tout nettoyer!!

private:
	PartieDeclarative partieDeclarative;
	PartieInstructive partieInstructive;

};

#endif 
