#if !defined ( PROGRAMME_H )
#define PROGRAMME_H
#include "Symbole.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"

using namespace std;


class Programme : public Symbole {

public:
	Programme(PartieDeclarative *partieD, PartieInstructive *partieI);
	Programme():Symbole(Identifiants::ID_PROGRAMME){}
	virtual ~Programme(){} //TODO: tout nettoyer!!

	void afficherVariables();
	// map<string,double> getVariables();		
	void executer(){executer(map_variables);}
	virtual void executer(map<string,double> &mapV);

	
	map<string,double> getMap(){return map_variables;}

private:
	PartieDeclarative *partieDeclarative;
	PartieInstructive *partieInstructive;
	map<string,double> map_variables;

};

#endif 
