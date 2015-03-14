#if !defined ( CONSTANTE_H )
#define CONSTANTE_H
#include "Expression.h"

#include <string>


class Constante : public Expression {

public:
	Constante(double v, string n);
	virtual ~Constante(){}

private:
	string nom;
	double valeur;

};


#endif 