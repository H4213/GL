#if !defined ( NOMBRE_H )
#define NOMBRE_H
#include "Expression.h"
#include "Identifiants.h"

#include <string>


class Nombre : public Expression {

public:
	Nombre(double v);
	Nombre():Expression(Identifiants::ID_NOMBRE){}
	virtual ~Nombre(){}

private:
	double valeur;

};


#endif 