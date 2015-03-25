#if !defined ( TERME_H )
#define TERME_H
#include "Terme.h"

class Facteur : public Terme 
{

public:
	Facteur();
	Facteur(int id):Terme(id){}
	virtual ~Facteur(){}
	
	virtual double eval(map<string,double> &mapV){}

};


#endif