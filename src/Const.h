#if !defined ( CONST_H )
#define CONST_H
#include "Symbole.h"


class Const : public Symbole {

public:
	Const();
	virtual ~Const(){}
	
	virtual void executer(map<string,double> &mapV){}

};


#endif 
