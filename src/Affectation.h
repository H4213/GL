#if !defined ( AFFECTATION_H )
#define AFFECTATION_H
#include "Symbole.h"


class Affectation : public Symbole {

public:
	Affectation();
	virtual ~Affectation(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};


	#endif 