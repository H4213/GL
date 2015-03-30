#if !defined ( ID_H )
#define ID_H
#include "Symbole.h"
#include "Facteur.h"
#include "Nombre.h"

class Id : public Facteur {

public :
	Id(string nom);
	Id():Facteur(Identifiants::ID_ID){}
	virtual ~Id(){}
	virtual void executer(map<string,double> &mapV){}
	bool operator==(const Id &);

	void convertToFacteur(){_ident = Identifiants::ID_FACTEUR;} 
	Expression* transformation(map<string,double>  constantes);

	vector<Id*> getIds();
	string getNom() const;
};


#endif
