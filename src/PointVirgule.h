#if !defined ( POINTVIRGULE_H )
#define POINTVIRGULE_H
#include "Symbole.h"


class PointVirgule : public Symbole {

public:
	PointVirgule();
	virtual ~PointVirgule(){}
	
	virtual void executer(map<string,double> &mapV){}

};


#endif 