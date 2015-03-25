#if !defined ( NOMBRE_H )
#define NOMBRE_H
#include "Expression.h"

class Nombre : public Expression {

public:
	Nombre(double v);
	Nombre():Expression(Identifiants::ID_NOMBRE){}
	virtual ~Nombre(){}
	
	double getValeur();
	virtual double eval(map<string,double> &mapV);
	vector<string> getIds(){}
private:
	double valeur;

};


#endif 
