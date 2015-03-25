#if !defined ( VARIABLE_H )
#define VARIABLE_H
#include "Expression.h"

class Variable : public Expression {

public:
	Variable(string n);
<<<<<<< HEAD
	Variable(){};
	virtual ~Variable(){};
    string getNom();
=======
	Variable():Expression(Identifiants::ID_VARIABLE){}
	virtual ~Variable(){}
	
	string getNom();
	virtual double eval(map<string,double> &mapV);	
>>>>>>> eba44e39f24c62f3d560db3081ec1095d5871ea5

private:
	string nom;

};


#endif
