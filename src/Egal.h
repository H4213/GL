#if !defined ( EGAL_H )
#define EGAL_H
#include "Symbole.h"


class Egal : public Symbole {

public:
	Egal();
	virtual ~Egal(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}
};


#endif 