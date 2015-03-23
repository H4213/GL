#if !defined ( ID_H )
#define ID_H
#include "Symbole.h"


class Id : public Symbole {

public:
	Id(string nom);
	Id():Symbole(Identifiants::ID_ID){}
	virtual ~Id(){}
	
	virtual void executer(map<string,double> &mapV){}

};


#endif 