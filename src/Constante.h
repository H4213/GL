#if !defined ( CONSTANTE_H )
#define CONSTANTE_H
#include "Expression.h"

#include <string>


class Constante : public Expression {

public:
	Constante(string n, double v);
	Constante():Expression(Identifiants::ID_CONSTANTE){}
	virtual ~Constante(){}
	
	virtual void executer(map<string,double> &mapV);
	// Expression Eval();
	string getNom();
	double getValeur();

private:
	string nom;
	double valeur;

};


#endif 