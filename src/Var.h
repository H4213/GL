#if !defined ( VAR_H )
#define VAR_H
#include "Symbole.h"


class Var : public Symbole {

public:
	Var();
	virtual ~Var(){}
	
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};


#endif 