#if !defined ( CONSTANTE_H )
#define CONSTANTE_H
#include "Expression.h"

#include <string>


class Constante : public Expression {

public:
	Constante(string n, double v);
<<<<<<< HEAD
	Constante(){};
	virtual ~Constante(){};
    string getNom();
    double getValeur();
=======
	Constante():Expression(Identifiants::ID_CONSTANTE){}
	virtual ~Constante(){}
	
	string getNom();
	double getValeur();
	virtual double eval(map<string,double> &mapV);
>>>>>>> eba44e39f24c62f3d560db3081ec1095d5871ea5

private:
	string nom;
	double valeur;

};


#endif
