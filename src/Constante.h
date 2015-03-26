#if !defined ( CONSTANTE_H )
#define CONSTANTE_H
#include "Facteur.h"

#include <string>

class Constante : public Symbole {

public:
	Constante(string n, double v);
	Constante():Symbole(Identifiants::ID_CONSTANTE){est_vide = true;}
	virtual ~Constante(){}

	string getNom();
	double getValeur();
	virtual double eval(map<string,double> &mapV);


private:
	string nom;
	double valeur;

};


#endif
