#if !defined ( VIRGULE_H )
#define VIRGULE_H
#include "Symbole.h"


class Virgule : public Symbole {

public:
	Virgule();
	virtual ~Virgule(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};


#endif 