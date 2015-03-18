#if !defined ( CONSTANTE_H )
#define CONSTANTE_H
#include "Expression.h"
#include "Identifiants.h"

#include <string>


class Constante : public Expression {

public:
	Constante(string n, double v);
	Constante():Expression(Identifiants::ID_CONSTANTE){}
	virtual ~Constante(){}

private:
	string nom;
	double valeur;

};


#endif 