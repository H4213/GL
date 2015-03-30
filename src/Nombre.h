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
	virtual double eval(map<string,double> &mapV);
	vector<Id*> getIds();
	Expression* transformation(map<string,double> constantes);

	void convertToFacteur(){_ident = Identifiants::ID_FACTEUR;}

private:
	double valeur;

};


#endif
