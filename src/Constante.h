#if !defined ( CONSTANTE_H )
#define CONSTANTE_H
#include "Expression.h"
#include "Identifiants.h"

#include <string>


class Constante : public Expression {

public:
	Constante(string n, double v);
	Constante(){}
	virtual ~Constante():Expression(Identifiants::ID_CONSTANTE){}

private:
	string nom;
	double valeur;

};


#endif 