#if !defined ( NOMBRE_H )
#define NOMBRE_H
#include "Facteur.h"

class Nombre : public Facteur 
{

public:
	Nombre(string v);
	Nombre():Facteur(Identifiants::ID_NOMBRE){est_vide = true;}
	virtual ~Nombre(){}

	double getValeur();
	string getStrValeur();
	vector<Id*> getIds();	
	void convertToFacteur(){_ident = Identifiants::ID_FACTEUR;}
	virtual double eval(map<string,double> &mapV , map<string,double> &mapC);
	
private:
	double valeur;

};


#endif
