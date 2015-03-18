#if !defined ( NOMBRE_H )
#define NOMBRE_H
#include "Expression.h"

#include <string>


class Nombre : public Expression {

public:
	Nombre(double v);
	virtual ~Nombre(){}

private:
	double valeur;

};


#endif 