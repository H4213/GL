#if !defined ( FERMEPARENTHESE_H )
#define FERMEPARENTHESE_H
#include "Symbole.h"

class FermeParenthese : public Symbole{

public:
	FermeParenthese();
	virtual ~FermeParenthese(){}
	
	virtual void executer(map<string,double> &mapV){}

};

#endif 