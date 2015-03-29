#if !defined ( LIRE_H )
#define LIRE_H
#include "Symbole.h"

class Lire : public Symbole{

public:
	Lire();
	virtual ~Lire(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};



#endif 