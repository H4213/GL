#if !defined ( NOMBRE_H )
#define NOMBRE_H
#include "Facteur.h"

class Nombre : public Facteur {

public:
	Nombre(string v);
	Nombre():Facteur(Identifiants::ID_NOMBRE){est_vide = true;}
	virtual ~Nombre(){}

	double getValeur();
	virtual double eval(map<string,double> &mapV);

private:
	double valeur;

};


#endif
