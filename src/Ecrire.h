#if !defined ( ECRIRE_H )
#define ECRIRE_H
#include "Symbole.h"

class Ecrire : public Symbole{

public:
	Ecrire();
	virtual ~Ecrire(){}
	
	virtual void executer();

};


#endif 
