#if !defined ( FACTEUR_H )
#define FACTEUR_H
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