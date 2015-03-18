#if !defined ( PROGRAMME_H )
#define PROGRAMME_H
#include "Symbole.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"


class Programme : public Symbole {

public:
	Programme(PartieDeclarative partieD, PartieInstructive partieI);
	virtual ~Programme(){}

private:
	PartieDeclarative partieDeclarative;
	PartieInstructive partieInstructive;

};

#endif 
