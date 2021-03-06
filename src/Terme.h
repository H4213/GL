#if !defined ( TERME_H )
#define TERME_H
#include "Expression.h"
//#include "Id.h"
class Id;
class Terme : public Expression
{

public:
	Terme();
	Terme(int id):Expression(id){}
	virtual ~Terme(){}
	
	vector<Id*> getIds();
	virtual double eval(map<string,double> &mapV , map<string,double> &mapC){}
	void convertToExpression(){_ident=Identifiants::ID_EXPRESSION;}
	virtual Expression* transformation(map<string,double> constantes);
};


#endif
