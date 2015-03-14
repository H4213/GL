#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"

class PartieDeclarative : public Symbole {

public:
	PartieDeclarative();
	virtual ~PartieDeclarative(){}

private:
	Declaration declaration;
	PartieDeclarative sousPartieDeclarative;

};


#endif 