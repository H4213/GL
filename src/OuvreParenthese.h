#if !defined ( OUVREPARENTHESE_H )
#define OUVREPARENTHESE_H
#include "Symbole.h"

class OuvreParenthese : public Symbole{

public:
	OuvreParenthese();
	virtual ~OuvreParenthese(){}
	
	virtual void executer(map<string,double> &mapV){}
};

#endif 
