#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Facteur.h"

class Variable : public Facteur {

public:
	Variable(string n);
	Variable():Facteur(Identifiants::ID_VARIABLE){est_vide = true;}
	virtual ~Variable(){}
	string getNom();
	virtual double eval(map<string,double> &mapV);

private:
	string nom;

};


#endif
