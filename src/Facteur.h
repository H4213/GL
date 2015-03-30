#if !defined ( FACTEUR_H )
#define FACTEUR_H
#include "Terme.h"
#include <vector>

class Facteur : public Terme
{

public:
	Facteur();
	Facteur(int id):Terme(id){}
	virtual ~Facteur(){}
	virtual vector<Id*> getIds();

	virtual Expression* transformation(map<string,double>constantes);

	virtual double eval(map<string,double> &mapV , map<string,double> &mapC){}


	void convertToTerme(){_ident=Identifiants::ID_TERME;}

};


#endif
